#include <string>
#include <stdint.h>
#include <iostream>

#include "../include/thisinh.h"

std::string khoiThiToString(const khoi_thi_t &khoi_thi) {
    switch (khoi_thi) {
        case khoi_thi_t::KHOI_A:
            return "Khoi A (Toan, Ly, Hoa)";
        case khoi_thi_t::KHOI_B:
            return "Khoi B (Toan, Hoa, Sinh)";
        case khoi_thi_t::KHOI_C:
            return "Khoi C (Van, Su, Dia)";
        default:
            return "";
    }
}

khoi_thi_t stringToKhoiThi(const std::string &str) {
    if(str == "A") {
        return khoi_thi_t::KHOI_A;
    }
    else if(str == "B") {
        return khoi_thi_t::KHOI_B;
    }
    else if(str == "C") {
        return khoi_thi_t::KHOI_C;
    }
    else {
        return khoi_thi_t::KHOI_A;
    }
}

// Định nghĩa các phương thức của lớp cán bộ
ThiSinh::ThiSinh() : sbd(""), ho_ten(""), dia_chi(""), muc_uu_tien(0) {}

ThiSinh::ThiSinh(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien) {
    this->setSBD(sbd);
    this->setHoten(ho_ten);
    this->setDiachi(dia_chi);
    this->setMucUuTien(muc_uu_tien);
}

ThiSinh::~ThiSinh() {

}

std::string ThiSinh::getSBD() const { return this->sbd; }

std::string ThiSinh::getHoten() const { return this->ho_ten; }

uint8_t ThiSinh::getMucUuTien() const { return this->muc_uu_tien; }

std::string ThiSinh::getDiachi() const { return this->dia_chi; }

bool ThiSinh::setSBD(const std::string &sbd) {
    if(sbd.length() != SBD_LENGTH) return false;
    this->sbd = sbd;
    return true;
}

bool ThiSinh::setHoten(const std::string &ho_ten) {
    if(ho_ten.length() == 0) return false;
    this->ho_ten = ho_ten;
    return true;
}

bool ThiSinh::setMucUuTien(const uint8_t &muc_uu_tien) {
    this->muc_uu_tien = muc_uu_tien;
    return true;
}

bool ThiSinh::setDiachi(const std::string &dia_chi) {
    this->dia_chi = dia_chi;
    return true;
}

std::string ThiSinh::toString() const {
    return "So bao danh: " + this->getSBD() + "\n" 
        + "Ho ten: " + this->getHoten() + "\n" 
        + "Dia chi: " + this->getDiachi() + "\n"
        + "Muc uu tien: " + std::to_string(this->getMucUuTien()) + "\n"
        + "Khoi thi: " + khoiThiToString(this->getKhoiThi()) + "\n";
}

// Định nghĩa các phương thức của lớp công nhân
ThiSinhKhoiA::ThiSinhKhoiA() : ThiSinh() { }

ThiSinhKhoiA::ThiSinhKhoiA(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien) 
            : ThiSinh(sbd, ho_ten, dia_chi, muc_uu_tien) { }

ThiSinhKhoiA::~ThiSinhKhoiA() {

}

khoi_thi_t ThiSinhKhoiA::getKhoiThi() const {
    return khoi_thi_t::KHOI_A;
}

// Định nghĩa các phương thức của lớp kỹ sư
ThiSinhKhoiB::ThiSinhKhoiB() : ThiSinh() { }

ThiSinhKhoiB::ThiSinhKhoiB(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien) 
            : ThiSinh(sbd, ho_ten, dia_chi, muc_uu_tien) { }

ThiSinhKhoiB::~ThiSinhKhoiB() {

}

khoi_thi_t ThiSinhKhoiB::getKhoiThi() const {
    return khoi_thi_t::KHOI_B;
}

// Định nghĩa các phương thức của lớp nhân viên
ThiSinhKhoiC::ThiSinhKhoiC() : ThiSinh() { }

ThiSinhKhoiC::ThiSinhKhoiC(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien) 
            : ThiSinh(sbd, ho_ten, dia_chi, muc_uu_tien) { }

ThiSinhKhoiC::~ThiSinhKhoiC() {

}

khoi_thi_t ThiSinhKhoiC::getKhoiThi() const {
    return khoi_thi_t::KHOI_C;
}