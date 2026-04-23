#include "cListCandidate.h"
#include <algorithm>

void cListCandidate::Nhap()
{
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;

    ds.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thi sinh thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void cListCandidate::XuatLonHon15()
{
    cout << "\nDanh sach thi sinh co tong diem > 15:\n";
    for (auto &x : ds)
    {
        if (x.TongDiem() > 15)
        {
            x.Xuat();
            cout << "-----------------\n";
        }
    }
}

void cListCandidate::ThiSinhCaoDiemNhat()
{
    if (ds.empty()) return;

    int idx = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i].TongDiem() > ds[idx].TongDiem())
            idx = i;
    }

    cout << "\nThi sinh co tong diem cao nhat:\n";
    ds[idx].Xuat();
}

void cListCandidate::SapXepGiamDan()
{
    sort(ds.begin(), ds.end(), [](cCandidate a, cCandidate b)
    {
        return a.TongDiem() > b.TongDiem();
    });
}

void cListCandidate::XuatDanhSach()
{
    cout << "\nDanh sach thi sinh:\n";
    for (auto &x : ds)
    {
        x.Xuat();
        cout << "-----------------\n";
    }
}
