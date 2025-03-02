#include <bits/stdc++.h>

#include "./include/thisinh.h"
#include "./include/tuyensinh.h"

using namespace std;

int main() {
    TuyenSinh qlts;
    cout << "Chuong trinh quan ly tuyen sinh\n";
    cout << "***************************\n";
    cout << "Nhan phim p de in ra danh sach tuyen sinh.\n";
    cout << "Nhan phim a de them moi tuyen sinh vao danh sach.\n";
    cout << "Nhan phim s de tim kiem thi sinh theo so bao danh.\n";
    cout << "Nhan phim e de thoat khoi chuong trinh.\n";
    cout << "***************************\n";

    string cmd;
    while(1) {
        cout << "\nNhap cau lenh: ";
        getline(cin, cmd);

        if(cmd == "p") {
            if(qlts.getDanhSach().size() == 0) {
                cout << "Danh sach trong.\n";
                continue;
            }
            cout << "Danh sach thi sinh:\n";
            qlts.printDanhSach(qlts.getDanhSach());
        }
        
        else if(cmd == "a") {
            cout << "Nhap thong tin cua thi sinh duoc them moi:\n";
            ThiSinh *thisinh;

            string sbd;
            cout << "So bao danh (" << SBD_LENGTH << " ky tu): ";
            getline(cin, sbd);

            string ho_ten;
            cout << "Ho ten: ";
            getline(cin, ho_ten);

            string dia_chi;
            cout << "Dia chi: ";
            getline(cin, dia_chi);

            unsigned int muc_uu_tien;
            cout << "Muc uu tien: ";
            cin >> muc_uu_tien;
            cin.ignore();

            string khoi_thi;
            cout << "Khoi thi: ";
            getline(cin, khoi_thi);

            if(stringToKhoiThi(khoi_thi) == khoi_thi_t::KHOI_A) {
                thisinh = new ThiSinhKhoiA(sbd, ho_ten, dia_chi, muc_uu_tien);
            }
            else if(stringToKhoiThi(khoi_thi) == khoi_thi_t::KHOI_B) {
                thisinh = new ThiSinhKhoiB(sbd, ho_ten, dia_chi, muc_uu_tien);
            }
            else if(stringToKhoiThi(khoi_thi) == khoi_thi_t::KHOI_C) {
                thisinh = new ThiSinhKhoiC(sbd, ho_ten, dia_chi, muc_uu_tien);
            }

            bool valid = qlts.addThiSinh(thisinh);
            if(valid) cout << "Thi sinh moi duoc them thanh cong vao danh sach.\n";
            else cout << "Thong tin khong hop le (cac truong thong tin bi nhap sai hoac so bao danh da ton tai).\n";
            delete thisinh;
        }

        else if(cmd == "s") {
            if(qlts.getDanhSach().size() == 0) {
                cout << "Danh sach trong.\n";
                continue;
            }

            string ho_ten;
            cout << "Ho ten cua thi sinh can duoc tim kiem: ";
            getline(cin, ho_ten);

            const ThiSinh* ketqua =  qlts.searchThiSinhBySBD(ho_ten);
            if(ketqua == NULL) {
                cout << "Khong tim thay ket qua phu hop.\n";
                continue;
            }
            cout << "Ket qua tim kiem:\n" << ketqua->toString() << "\n";
        }

        else if(cmd == "e") {
            qlts.exitProgram();
        }

        else {
            cout << "Cau lenh khong hop le.\n";
        }
    }
}