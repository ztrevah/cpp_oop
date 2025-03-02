#ifndef _CAN_BO_H_
#define _CAN_BO_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <unordered_map>

typedef enum {
    NAM,
    NU,
    KHAC
} gioi_tinh_t;
std::istream& operator>>(std::istream& is, gioi_tinh_t& gioi_tinh);
std::ostream& operator<<(std::ostream& os, const gioi_tinh_t& gioi_tinh);

typedef enum {
    CHUCVU_CONGNHAN,
    CHUCVU_KYSU,
    CHUCVU_NHANVIEN
} chucvu_canbo_t;
std::istream& operator>>(std::istream& is, chucvu_canbo_t &chuc_vu);
std::ostream& operator<<(std::ostream& os, const chucvu_canbo_t& chucvu);

class CanBo {
protected:
    std::string ho_ten;
    uint8_t tuoi;
    gioi_tinh_t gioi_tinh;
    std::string dia_chi;
public:
    CanBo();
    CanBo(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi);
    ~CanBo();
    std::string getHoten() const;
    uint8_t getTuoi() const;
    gioi_tinh_t getGioitinh() const;
    std::string getDiachi() const;

    bool setHoten(const std::string &ho_ten);
    bool setTuoi(const uint8_t &tuoi);
    bool setGioitinh(const gioi_tinh_t &gioi_tinh);
    bool setDiachi(const std::string &dia_chi);

    virtual chucvu_canbo_t getChucVu() const = 0;
};

class CongNhan : public CanBo {
private:
    uint8_t bac;
public:
    CongNhan();
    CongNhan(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, uint8_t bac);
    ~CongNhan();
    uint8_t getBac() const;

    bool setBac(const uint8_t &bac);

    chucvu_canbo_t getChucVu() const;

    friend std::ostream& operator<<(std::ostream& os, const CongNhan& dt);
};

class KySu : public CanBo {
private:
    std::string nganh_dao_tao;
public:
    KySu();
    KySu(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, std::string nganh_dao_tao);
    ~KySu();
    std::string getNganhDaoTao() const;

    bool setNganhDaoTao(const std::string &nganh_dao_tao);

    chucvu_canbo_t getChucVu() const;

    friend std::ostream& operator<<(std::ostream& os, const KySu& dt);
};

class NhanVien : public CanBo {
private:
    std::string cong_viec;
public:
    NhanVien();
    NhanVien(std::string ho_ten,uint8_t tuoi,gioi_tinh_t gioi_tinh,std::string dia_chi, std::string cong_viec);
    ~NhanVien();
    std::string getCongViec() const;

    bool setCongViec(const std::string &cong_viec);

    chucvu_canbo_t getChucVu() const;

    friend std::ostream& operator<<(std::ostream& os, const NhanVien& dt);
};

#endif