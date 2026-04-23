#include "cNhanVienSX.h"
#include <ctime>

cNhanVienSX::cNhanVienSX()
{
    ma = "";
    hoten = "";
    ngay = thang = nam = 0;
    soSP = 0;
    donGia = 0;
}

cNhanVienSX::cNhanVienSX(string m, string ht, int d, int t, int n, int sp, double dg)
{
    ma = m;
    hoten = ht;
    ngay = d;
    thang = t;
    nam = n;
    soSP = sp;
    donGia = dg;
}

void cNhanVienSX::Nhap()
{
    cout << "Nhap ma: ";
    cin >> ma;
    cin.ignore();

    cout << "Nhap ho ten: ";
    getline(cin, hoten);

    cout << "Nhap ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;

    cout << "Nhap so san pham: ";
    cin >> soSP;

    cout << "Nhap don gia: ";
    cin >> donGia;
}

void cNhanVienSX::Xuat()
{
    cout << "Ma: " << ma << endl;
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
    cout << "So SP: " << soSP << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Luong: " << TinhLuong() << endl;
    cout << "Tuoi: " << GetTuoi() << endl;
}

double cNhanVienSX::TinhLuong()
{
    return soSP * donGia;
}

int cNhanVienSX::GetTuoi()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    int namHT = now->tm_year + 1900;

    return namHT - nam;
}
