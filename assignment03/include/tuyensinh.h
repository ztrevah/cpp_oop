#ifndef _TUYEN_SINH_H_
#define _TUYEN_SINH_H_

#include <string>
#include <unordered_map>
#include "thisinh.h"

using namespace std;

class TuyenSinh {
private:
    unordered_map<string,ThiSinh*> danh_sach;
public:
    TuyenSinh();
    ~TuyenSinh();

    // void startProgram();

    unordered_map<string,ThiSinh*> getDanhSach();
    static void printDanhSach(const unordered_map<string,ThiSinh*> &danh_sach);
    bool addThiSinh(ThiSinh *thi_sinh);

    const ThiSinh* searchThiSinhBySBD(const string &sbd);

    void exitProgram();
};

#endif