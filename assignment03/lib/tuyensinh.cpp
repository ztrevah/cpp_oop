#include <iostream>

#include "../include/tuyensinh.h"

using std::cout;

TuyenSinh::TuyenSinh() {
    // Khởi tạo danh sách cán bộ
}

TuyenSinh::~TuyenSinh() {
    for(auto &rc: danh_sach) {
        delete rc.second;
    }
}

unordered_map<string,ThiSinh*> TuyenSinh::getDanhSach() { return danh_sach; }

void TuyenSinh::printDanhSach(const unordered_map<string,ThiSinh*> &danh_sach) {
    for(const auto &rc: danh_sach) {
        ThiSinh* ts = rc.second;
        switch(ts->getKhoiThi()) {
            case khoi_thi_t::KHOI_A:
                cout << ts->toString() << "\n";
                break;
            case khoi_thi_t::KHOI_B:
                cout << ts->toString() << "\n";
                break;
            case khoi_thi_t::KHOI_C:
                cout << ts->toString() << "\n";
                break;
            default:
                break;
        }
    }
}

bool TuyenSinh::addThiSinh(ThiSinh *thi_sinh) {
    ThiSinh* thi_sinh_moi;
    switch (thi_sinh->getKhoiThi()) {
        case khoi_thi_t::KHOI_A:
            thi_sinh_moi = new ThiSinhKhoiA;
            break;
        case khoi_thi_t::KHOI_B:
            thi_sinh_moi = new ThiSinhKhoiA;
            break;
        case khoi_thi_t::KHOI_C:
            thi_sinh_moi = new ThiSinhKhoiA;
            break;
        default:
            return false;
    }
    bool valid = thi_sinh_moi->setSBD(thi_sinh->getSBD()) && thi_sinh_moi->setHoten(thi_sinh->getHoten())
                && thi_sinh_moi->setDiachi(thi_sinh->getDiachi()) && thi_sinh_moi->setMucUuTien(thi_sinh->getMucUuTien());
    if(!valid) {
        delete thi_sinh_moi;
        return false;
    }
    try {
        ThiSinh* existing_ts = this->danh_sach.at(thi_sinh->getSBD());
        delete thi_sinh_moi;
        return false;
    } catch(...) {
        this->danh_sach[thi_sinh->getSBD()] = thi_sinh_moi;
        return true;
    }
}

const ThiSinh* TuyenSinh::searchThiSinhBySBD(const string &ho_ten) {
    try {
        ThiSinh* existing_ts = this->danh_sach.at(ho_ten);
        return existing_ts;
    } catch(...) {
        return NULL;
    }
}

void TuyenSinh::exitProgram() {
    for(auto &rc: danh_sach) {
        delete rc.second;
    }
    // cout << "Program exited";
    exit(0);
}