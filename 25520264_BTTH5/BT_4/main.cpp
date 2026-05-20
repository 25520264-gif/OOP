#include <iostream>
#include <vector>
#include "NhanVien.h"

using namespace std;

int main() {
    vector<NhanVien*> danhSach;
    int n;

    // a. Nhap danh sach
    cout << "Nhap so luong nhan vien can them: "; cin >> n;
    for (int i = 0; i < n; i++)
        {
        cout << "\n--- Nhap thong tin nhan vien thu: " << i + 1 << " ---\n";
        cout << "Chon loai (1 - Lap trinh vien, 2 - Kiem chung vien): ";
        int chon; cin >> chon;

        NhanVien* nv = nullptr;
        if (chon == 1)
            nv = new LapTrinhVien();
        else if (chon == 2)
            nv = new KiemChungVien();
        else
        {
            cout << "Lua chon khong hop le! Mac dinh chon lap trinh vien.\n";
            nv = new LapTrinhVien();
        }
        cin>> *nv;
        danhSach.push_back(nv);
    }

    if (danhSach.empty()) {
        cout << "\nDanh sach trong!";
        return 0;
    }

    // b. Xuat danh sach
    cout << "\n================ B. DANH SACH TAT CA NHAN VIEN ================";
    for (const auto& nv : danhSach) {
        cout<< *nv;
    }

    // Tinh/tim luong
    double tongLuong = 0;
    double luongMax = -1, luongMin = 1e18;
    double maxLuongLTV = -1, minLuongKCV = 1e18;

    for (const auto& nv : danhSach) {
        double luong = nv->tinhLuong();
        tongLuong += luong;

        if (luong > luongMax) luongMax = luong;
        if (luong < luongMin) luongMin = luong;

        if (nv->loaiNhanVien() == 1 && luong > maxLuongLTV) maxLuongLTV = luong;
        if (nv->loaiNhanVien() == 2 && luong < minLuongKCV) minLuongKCV = luong;
    }
    double luongTrungBinh = tongLuong / danhSach.size();

    // c. Danh sach nhan vien luong thap hon trung binh
    cout << "\n================ C. NHAN VIEN LUONG THAP HON TRUNG BINH(" << fixed << setprecision(0) << luongTrungBinh << ") ================";
    for (const auto& nv : danhSach) {
        if (nv->tinhLuong() < luongTrungBinh) cout<< *nv;
    }

    // d. Nhan vien luong cao nhat
    cout << "\n================ D. NHAN VIEN CO LUONG CAO NHAT ================";
    for (const auto& nv : danhSach) {
        if (nv->tinhLuong() == luongMax) cout<< *nv;
    }

    // e. Nhan vien luong thap nhat
    cout << "\n================ E. NHAN VIEN CO LUONG THAP NHAT ================";
    for (const auto& nv : danhSach) {
        if (nv->tinhLuong() == luongMin) cout<< *nv;
    }

    // f. Lap trinh vien luong cao nhat
    cout << "\n================ F. LAP TRINH VIEN CO LUONG CAO NHAT ================";
    if (maxLuongLTV == -1) {
        cout << "Khong co lap trinh vien trong danh sach.\n";
    } else {
        for (const auto& nv : danhSach) {
            if (nv->loaiNhanVien() == 1 && nv->tinhLuong() == maxLuongLTV) cout<< *nv;
        }
    }

    // g. Kiem chung vien luong thap nhat
    cout << "\n================ G. KIEM CHUNG VIEN CO LUONG THAP NHAT ================";
    if (minLuongKCV == 1e18) {
        cout << "Khong co kiem chung vien trong danh sach.\n";
    } else {
        for (const auto& nv : danhSach) {
            if (nv->loaiNhanVien() == 2 && nv->tinhLuong() == minLuongKCV) cout<< *nv;
        }
    }

    // delete
    for (auto nv : danhSach) {
        delete nv;
    }
    danhSach.clear();

    return 0;
}
