#include <bits/stdc++.h>

#include "./include/can_bo.h"
#include "./include/qlcb.h"

using namespace std;

int main() {
    QLCB qlcb;
    cout << "Chuong trinh quan ly can bo\n";
    cout << "***************************\n";
    cout << "Nhan phim p de in ra danh sach can bo.\n";
    cout << "Nhan phim a de them moi can bo vao danh sach.\n";
    cout << "Nhan phim s de tim kiem can bo theo ten.\n";
    cout << "Nhan phim e de thoat khoi chuong trinh.\n";
    cout << "***************************\n";

    string cmd;
    while(1) {
        cout << "\nNhap cau lenh: ";
        getline(cin, cmd);

        if(cmd == "p") {
            if(qlcb.getDanhSach().size() == 0) {
                cout << "Danh sach trong.\n";
                continue;
            }
            cout << "Danh sach can bo:\n";
            qlcb.printDanhSach(qlcb.getDanhSach());
        }
        
        else if(cmd == "a") {
            cout << "Nhap thong tin cua can bo duoc them moi:\n";
            CanBo *canbo;

            string ho_ten;
            cout << "Ho ten: ";
            getline(cin, ho_ten);
            
            unsigned int tuoi;
            cout << "Tuoi: ";
            cin >> tuoi;
            cin.ignore();

            gioi_tinh_t gioi_tinh;
            cout << "Gioi tinh (0 - nam, 1 - nu, 2 - khac): ";
            cin >> gioi_tinh;
            cin.ignore();

            string dia_chi;
            cout << "Dia chi: ";
            getline(cin, dia_chi);

            chucvu_canbo_t chuc_vu;
            cout << "Chuc vu nhan vien (0 - cong nhan, 1 - ky su, 2 - nhan vien): ";
            cin >> chuc_vu;
            cin.ignore();

            if(chuc_vu == chucvu_canbo_t::CHUCVU_CONGNHAN) {
                uint8_t bac;
                cout << "Bac (1 - 10): ";
                cin >> bac;
                cin.ignore();
                canbo = new CongNhan(ho_ten, tuoi, gioi_tinh, dia_chi, bac);
            }
            else if(chuc_vu == chucvu_canbo_t::CHUCVU_KYSU) {
                string nganh_dao_tao;
                cout << "Nganh dao tao: ";
                getline(cin, nganh_dao_tao);
                canbo = new KySu(ho_ten, tuoi, gioi_tinh, dia_chi, nganh_dao_tao);
            }
            else if(chuc_vu == chucvu_canbo_t::CHUCVU_NHANVIEN) {
                string cong_viec;
                cout << "Cong viec: ";
                getline(cin, cong_viec);
                canbo = new NhanVien(ho_ten, tuoi, gioi_tinh, dia_chi, cong_viec);
            }

            bool valid = qlcb.addCanBo(canbo);
            if(valid) cout << "Nhan vien moi duoc them thanh cong vao danh sach.\n";
            else cout << "Thong tin khong hop le.\n";
            delete canbo;
        }

        else if(cmd == "s") {
            if(qlcb.getDanhSach().size() == 0) {
                cout << "Danh sach trong.\n";
                continue;
            }

            string ho_ten;
            cout << "Ho ten cua can bo can duoc tim kiem: ";
            getline(cin, ho_ten);

            vector<CanBo*> ketqua =  qlcb.searchCanBoByHoTen(ho_ten);
            if(ketqua.size() == 0) {
                cout << "Khong tim thay ket qua phu hop.\n";
                continue;
            }
            cout << "Ket qua tim kiem:\n";
            qlcb.printDanhSach(ketqua);
        }

        else if(cmd == "e") {
            qlcb.exitProgram();
        }

        else {
            cout << "Cau lenh khong hop le.\n";
        }
    }
}