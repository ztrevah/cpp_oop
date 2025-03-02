#ifndef _QLCB_H_
#define _QLCB_H_

#include <string>
#include <vector>
#include "can_bo.h"

using namespace std;

class QLCB {
private:
    vector<CanBo*> danh_sach;
    bool addCongNhan(CongNhan *cong_nhan);
    bool addKySu(KySu *ky_su);
    bool addNhanVien(NhanVien *nhan_vien);
public:
    QLCB();
    ~QLCB();

    // void startProgram();

    vector<CanBo*> getDanhSach();
    static void printDanhSach(const vector<CanBo*> &danh_sach);
    bool addCanBo(CanBo *can_bo);

    const vector<CanBo*> searchCanBoByHoTen(string ho_ten);

    void exitProgram();
};

#endif