#ifndef _THI_SINH_H_
#define _THI_SINH_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <unordered_map>

typedef enum {
    KHOI_A,
    KHOI_B,
    KHOI_C
} khoi_thi_t;
std::string khoiThiToString(const khoi_thi_t &khoi_thi);
khoi_thi_t stringToKhoiThi(const std::string &str);

class ThiSinh {
protected:
    #define SBD_LENGTH 10
    std::string sbd;
    std::string ho_ten;
    std::string dia_chi;
    uint8_t muc_uu_tien;
public:
    ThiSinh();
    ThiSinh(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien);
    ~ThiSinh();
    std::string getSBD() const;
    std::string getHoten() const;
    std::string getDiachi() const;
    uint8_t getMucUuTien() const;

    bool setSBD(const std::string &ho_ten);
    bool setHoten(const std::string &ho_ten);
    bool setDiachi(const std::string &dia_chi);
    bool setMucUuTien(const uint8_t &muc_uu_tien);

    virtual khoi_thi_t getKhoiThi() const = 0;
    virtual std::string toString() const;
};

class ThiSinhKhoiA : public ThiSinh {
private:

public:
    ThiSinhKhoiA();
    ThiSinhKhoiA(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien);
    ~ThiSinhKhoiA();

    khoi_thi_t getKhoiThi() const;
};

class ThiSinhKhoiB : public ThiSinh {
private:

public:
    ThiSinhKhoiB();
    ThiSinhKhoiB(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien);
    ~ThiSinhKhoiB();

    khoi_thi_t getKhoiThi() const;
};

class ThiSinhKhoiC : public ThiSinh {
private:

public:
    ThiSinhKhoiC();
    ThiSinhKhoiC(std::string sbd,std::string ho_ten,std::string dia_chi,uint8_t muc_uu_tien);
    ~ThiSinhKhoiC();

    khoi_thi_t getKhoiThi() const;
};

#endif