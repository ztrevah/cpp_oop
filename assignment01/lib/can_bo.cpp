#include <string>
#include <stdint.h>
#include <iostream>

#include "../include/can_bo.h"

// Định nghĩa các phương thức của lớp cán bộ
CanBo::CanBo() : ho_ten(""), tuoi(0), gioi_tinh(KHAC), dia_chi("") {}

CanBo::CanBo(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi) {
    this->setHoten(ho_ten);
    this->setTuoi(tuoi);
    this->setGioitinh(gioi_tinh);
    this->setDiachi(dia_chi);
}

CanBo::~CanBo() {

}

std::string CanBo::getHoten() const { return this->ho_ten; }

uint8_t CanBo::getTuoi() const { return this->tuoi; }

gioi_tinh_t CanBo::getGioitinh() const { return this->gioi_tinh; }

std::string CanBo::getDiachi() const { return this->dia_chi; }

bool CanBo::setHoten(const std::string &ho_ten) {
    if(ho_ten.length() == 0) return false;
    this->ho_ten = ho_ten;
    return true;
}

bool CanBo::setTuoi(const uint8_t &tuoi) {
    this->tuoi = tuoi;
    return true;
}

bool CanBo::setGioitinh(const gioi_tinh_t &gioi_tinh) {
    this->gioi_tinh = (gioi_tinh != NAM && gioi_tinh != NU) ? KHAC : gioi_tinh;
    return true;
}

bool CanBo::setDiachi(const std::string &dia_chi) {
    this->dia_chi = dia_chi;
    return true;
}

// Định nghĩa các phương thức của lớp công nhân
CongNhan::CongNhan() : CanBo(), bac(1) {}

CongNhan::CongNhan(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, uint8_t bac) 
            : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi) {
    this->setBac(bac);
}

CongNhan::~CongNhan() {

}

uint8_t CongNhan::getBac() const { return this->bac; }

bool CongNhan::setBac(const uint8_t &bac) {
    this->bac = (bac < 1 || bac > 10) ? 10 : bac;
    return true;
}

chucvu_canbo_t CongNhan::getChucVu() const {
    return chucvu_canbo_t::CHUCVU_CONGNHAN;
}

// Định nghĩa các phương thức của lớp kỹ sư
KySu::KySu() : CanBo(), nganh_dao_tao("") {}

KySu::KySu(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, std::string nganh_dao_tao) 
            : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi) {
    this->setNganhDaoTao(nganh_dao_tao);
}

KySu::~KySu() {

}

std::string KySu::getNganhDaoTao() const { return this->nganh_dao_tao; }

bool KySu::setNganhDaoTao(const std::string &nganh_dao_tao) {
    this->nganh_dao_tao = nganh_dao_tao;
    return true;
}

chucvu_canbo_t KySu::getChucVu() const {
    return chucvu_canbo_t::CHUCVU_KYSU;
}

// Định nghĩa các phương thức của lớp nhân viên
NhanVien::NhanVien() : CanBo(), cong_viec("") {}

NhanVien::NhanVien(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, std::string cong_viec) 
            : CanBo(ho_ten, tuoi, gioi_tinh, dia_chi) {
    this->setCongViec(cong_viec);
}

NhanVien::~NhanVien() {

}

std::string NhanVien::getCongViec() const { return this->cong_viec; }

bool NhanVien::setCongViec(const std::string &cong_viec) {
    this->cong_viec = cong_viec;
    return true;
}

chucvu_canbo_t NhanVien::getChucVu() const {
    return chucvu_canbo_t::CHUCVU_NHANVIEN;
}

// Nạp chồng toán tử xuất thông tin công nhân
std::ostream& operator<<(std::ostream& os, const CongNhan& dt) {
    os << "Ho ten: " << dt.getHoten() << "\n" 
        << "Tuoi: " << (unsigned int) dt.getTuoi() << "\n" 
        << "Gioi tinh: " << dt.getGioitinh() << "\n"
        << "Dia chi: " << dt.getDiachi() << "\n"
        << "Chuc vu: " << dt.getChucVu() << "\n"
        << "Bac: " << dt.getBac() << "\n";
    return os;
}

// Nạp chồng toán tử xuất thông tin kỹ sư
std::ostream& operator<<(std::ostream& os, const KySu& dt) {
    os << "Ho ten: " << dt.getHoten() << "\n" 
        << "Tuoi: " << (unsigned int) dt.getTuoi() << "\n" 
        << "Gioi tinh: " << dt.getGioitinh() << "\n"
        << "Dia chi: " << dt.getDiachi() << "\n"
        << "Chuc vu: " << dt.getChucVu() << "\n"
        << "Nganh dao tao: " << dt.getNganhDaoTao() << "\n";
    return os;
}

// Nạp chồng toán tử xuất thông tin nhân viên
std::ostream& operator<<(std::ostream& os, const NhanVien& dt) {
    os << "Ho ten: " << dt.getHoten() << "\n" 
        << "Tuoi: " << (unsigned int) dt.getTuoi() << "\n" 
        << "Gioi tinh: " << dt.getGioitinh() << "\n"
        << "Dia chi: " << dt.getDiachi() << "\n"
        << "Chuc vu: " << dt.getChucVu() << "\n"
        << "Cong viec: " << dt.getCongViec() << "\n";
    return os;
}

// Nạp chồng toán tử nhập, xuất thông tin giới tính
std::istream& operator>>(std::istream& is, gioi_tinh_t& gioi_tinh) {
    unsigned int tmp;
    is >> tmp;
    switch(tmp) {
        case gioi_tinh_t::NAM:
            gioi_tinh = gioi_tinh_t::NAM;
            break;
        case gioi_tinh_t::NU:
            gioi_tinh = gioi_tinh_t::NU;
            break;
        default:
            gioi_tinh = gioi_tinh_t::KHAC;
            break;
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, const gioi_tinh_t& gioi_tinh) {
    switch (gioi_tinh) {
        case gioi_tinh_t::NAM:
            os << "Nam";
            break;
        case gioi_tinh_t::NU:
            os << "Nu";
            break;
        case gioi_tinh_t::KHAC:
            os << "Khac";
            break;
        default:
            break;
    }
    return os;
}

// Nạp chồng toán tử nhập, xuất thông tin chức vụ
std::istream& operator>>(std::istream& is, chucvu_canbo_t &chuc_vu) {
    unsigned int tmp;
    is >> tmp;
    chuc_vu = (chucvu_canbo_t) tmp;
    return is;
}
std::ostream& operator<<(std::ostream& os, const chucvu_canbo_t& chucvu) {
    switch (chucvu) {
        case chucvu_canbo_t::CHUCVU_CONGNHAN:
            os << "Cong nhan";
            break;
        case chucvu_canbo_t::CHUCVU_KYSU:
            os << "Ky su";
            break;
        case chucvu_canbo_t::CHUCVU_NHANVIEN:
            os << "Nhan vien";
            break;
        default:
            break;
    }
    return os;
}