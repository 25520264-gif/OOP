#include "cNhanVienVP.h"
#include <ctime>

// constructor mặc định
cNhanVienVP::cNhanVienVP()
{
    ma = "";
    hoten = "";
    ngay = thang = nam = 0;
    luong = 0;
}

// constructor đầy đủ
cNhanVienVP::cNhanVienVP(string m, string ht, int d, int t, int n, double l)
{
    ma = m;
    hoten = ht;
    ngay = d;
    thang = t;
    nam = n;
    luong = l;
}

void cNhanVienVP::Nhap()
{
    cout << "Nhap ma: ";
    cin >> ma;
    cin.ignore();

    cout << "Nhap ho ten: ";
    getline(cin, hoten);

    cout << "Nhap ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;

    cout << "Nhap luong: ";
    cin >> luong;
}

void cNhanVienVP::Xuat()
{
    cout << "Ma: " << ma << endl;
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
    cout << "Luong: " << luong << endl;
    cout << "Tuoi: " << GetTuoi() << endl;
}

// lấy lương
double cNhanVienVP::GetLuong()
{
    return luong;
}

// tính tuổi
int cNhanVienVP::GetTuoi()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    int namHT = now->tm_year + 1900;

    return namHT - nam;
}
