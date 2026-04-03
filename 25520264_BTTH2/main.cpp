#include <iostream>
#include "PhanSo.h"
#include "NgayThangNam.h"
#include "SoPhuc.h"
#include "GioPhutGiay.h"

using namespace std;

void Bai_1();
void Bai_2();
void Bai_3();
void Bai_4();

int main()
{
    int n;
    cout<< "1. Bai_1   2. Bai_2   3. Bai_3   4. Bai_4\n";
    cout<< "Chon bai muon kiem: ";
    cin>> n;

    switch(n)
    {
        case 1: Bai_1();break;
        case 2: Bai_2();break;
        case 3: Bai_3();break;
        case 4: Bai_4();break;
    }

    return 0;
}

void Bai_1()
{
    dmy n;

    cout<< "Nhap ngay thang nam hom nay: \n";
    n.Nhap();
    n.NgayThangNamTiepTheo();
    n.Xuat();
}

void Bai_2()
{
    PhanSo a, b;

    cout<< "Nhap phan so A:\n";
    a.Nhap();

    cout<< "Nhap phan so B:\n";
    b.Nhap();

    cout<< "\nPhan so A: ";
    a.RutGon();
    a.Xuat();

    cout<< "\nPhan so B: ";
    b.RutGon();
    b.Xuat();

    //Tinh toan
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong = a.Thuong(b);

    cout<< "\n\nTong: ";
    tong.Xuat();

    cout<< "\n\nHieu: ";
    hieu.Xuat();

    cout<< "\n\nTich: ";
    tich.Xuat();

    cout<< "\n\nThuong: ";
    thuong.Xuat();

    //So sanh
    int cmp = a.SoSanh(b);
    if(cmp == 1)
        cout<< "\nA > B";
    else if(cmp == 0)
        cout<< "\nA = B";
    else
        cout<< "\nA < B";
}

void Bai_3()
{
    SoPhuc a,b;

    cout<< "Nhap so phuc a:\n";
    a.Nhap();

    cout<< "Nhap so phuc b:\n";
    b.Nhap();

    //Tinh toan
    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);

    cout<< "\n\nTong: ";
    tong.Xuat();

    cout<< "\n\nHieu: ";
    hieu.Xuat();

    cout<< "\n\nTich: ";
    tich.Xuat();

    cout<< "\n\nThuong: ";
    thuong.Xuat();
}

void Bai_4()
{
    gpg g;

    cout<< "Nhap gio phut giay hien tai:\n";
    g.Nhap();
    g.TinhCongThemGiay();
    g.Xuat();
}
