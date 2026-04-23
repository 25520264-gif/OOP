#include "cListNhanVienVP.h"
#include <algorithm>

void cListNhanVienVP::Nhap()
{
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    ds.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void cListNhanVienVP::Xuat()
{
    cout << "\nDanh sach nhan vien:\n";
    for (auto &x : ds)
    {
        x.Xuat();
        cout << "-----------------\n";
    }
}

// lương cao nhất
void cListNhanVienVP::LuongCaoNhat()
{
    if (ds.empty()) return;

    int idx = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i].GetLuong() > ds[idx].GetLuong())
            idx = i;
    }

    cout << "\nNhan vien luong cao nhat:\n";
    ds[idx].Xuat();
}

// tổng lương
double cListNhanVienVP::TongLuong()
{
    double sum = 0;
    for (auto &x : ds)
        sum += x.GetLuong();

    return sum;
}

// tuổi cao nhất
void cListNhanVienVP::TuoiCaoNhat()
{
    if (ds.empty()) return;

    int idx = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i].GetTuoi() > ds[idx].GetTuoi())
            idx = i;
    }

    cout << "\nNhan vien tuoi cao nhat:\n";
    ds[idx].Xuat();
}

// sắp xếp tăng dần theo lương
void cListNhanVienVP::SapXepTangDanLuong()
{
    sort(ds.begin(), ds.end(), [](cNhanVienVP a, cNhanVienVP b)
    {
        return a.GetLuong() < b.GetLuong();
    });
}
