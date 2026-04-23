#include "cListNhanVienSX.h"
#include <algorithm>

void cListNhanVienSX::Nhap()
{
    int n;
    cout << "Nhap so nhan vien SX: ";
    cin >> n;

    ds.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void cListNhanVienSX::Xuat()
{
    cout << "\nDanh sach nhan vien SX:\n";
    for (auto &x : ds)
    {
        x.Xuat();
        cout << "-----------------\n";
    }
}

// lương thấp nhất
void cListNhanVienSX::LuongThapNhat()
{
    if (ds.empty()) return;

    int idx = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i].TinhLuong() < ds[idx].TinhLuong())
            idx = i;
    }

    cout << "\nNhan vien luong thap nhat:\n";
    ds[idx].Xuat();
}

// tổng lương
double cListNhanVienSX::TongLuong()
{
    double sum = 0;
    for (auto &x : ds)
        sum += x.TinhLuong();

    return sum;
}

// tuổi cao nhất
void cListNhanVienSX::TuoiCaoNhat()
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
void cListNhanVienSX::SapXepTangDanLuong()
{
    sort(ds.begin(), ds.end(), [](cNhanVienSX a, cNhanVienSX b)
    {
        return a.TinhLuong() < b.TinhLuong();
    });
}
