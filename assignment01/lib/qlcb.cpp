#include <iostream>

#include "../include/qlcb.h"

using std::cout;

QLCB::QLCB() {
    // Khởi tạo danh sách cán bộ
}

QLCB::~QLCB() {
    for(auto &cb: danh_sach) {
        delete cb;
    }
}

vector<CanBo*> QLCB::getDanhSach() { return danh_sach; }

void QLCB::printDanhSach(const vector<CanBo*> &danh_sach) {
    for(const auto &cb: danh_sach) {
        switch(cb->getChucVu()) {
            case chucvu_canbo_t::CHUCVU_CONGNHAN:
                cout << *((CongNhan*) cb) << "\n";
                break;
            case chucvu_canbo_t::CHUCVU_KYSU:
                cout << *((KySu*) cb) << "\n";
                break;
            case chucvu_canbo_t::CHUCVU_NHANVIEN:
                cout << *((NhanVien*) cb) << "\n";
                break;
            default:
                break;
        }
    }
}

bool QLCB::addCongNhan(CongNhan *cong_nhan) {
    CongNhan *tmp = new CongNhan;
    if(tmp->setHoten(cong_nhan->getHoten()) && tmp->setTuoi(cong_nhan->getTuoi()) 
        && tmp->setGioitinh(cong_nhan->getGioitinh()) && tmp->setDiachi(cong_nhan->getDiachi())
        && tmp->setBac(cong_nhan->getBac())) 
    {
        this->danh_sach.push_back(tmp);
        return true;
    }
    else {
        delete tmp;
        return false;
    }
}

bool QLCB::addKySu(KySu *ky_su) {
    KySu *tmp = new KySu;
    if(tmp->setHoten(ky_su->getHoten()) && tmp->setTuoi(ky_su->getTuoi()) 
        && tmp->setGioitinh(ky_su->getGioitinh()) && tmp->setDiachi(ky_su->getDiachi())
        && tmp->setNganhDaoTao(ky_su->getNganhDaoTao())) 
    {
        this->danh_sach.push_back(tmp);
        return true;
    }
    else {
        delete tmp;
        return false;
    }
}

bool QLCB::addNhanVien(NhanVien *nhan_vien) {
    NhanVien *tmp = new NhanVien;
    if(tmp->setHoten(nhan_vien->getHoten()) && tmp->setTuoi(nhan_vien->getTuoi()) 
        && tmp->setGioitinh(nhan_vien->getGioitinh()) && tmp->setDiachi(nhan_vien->getDiachi())
        && tmp->setCongViec(nhan_vien->getCongViec())) 
    {
        this->danh_sach.push_back(tmp);
        return true;
    }
    else {
        delete tmp;
        return false;
    }
}

bool QLCB::addCanBo(CanBo *can_bo) {
    chucvu_canbo_t chuc_vu = can_bo->getChucVu();
    switch (can_bo->getChucVu()) {
        case chucvu_canbo_t::CHUCVU_CONGNHAN:
            return addCongNhan((CongNhan*) can_bo);
        case chucvu_canbo_t::CHUCVU_KYSU:
            return addKySu((KySu*) can_bo);
        case chucvu_canbo_t::CHUCVU_NHANVIEN:
            return addNhanVien((NhanVien*) can_bo);
        default:
            return false;
    }
}

const vector<CanBo*> QLCB::searchCanBoByHoTen(string ho_ten) {
    vector<CanBo*> res;
    for(const auto &cb: danh_sach) {
        if(cb->getHoten() == ho_ten) res.push_back(cb);
    }
    return res;
}

void QLCB::exitProgram() {
    for(auto &cb: danh_sach) {
        delete cb;
    }
    // cout << "Program exited";
    exit(0);
}