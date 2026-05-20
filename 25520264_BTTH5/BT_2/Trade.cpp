#include "Trade.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <ctime>

typedef long long ll;

using namespace std;

Trade::Trade()
{
    maGiaoDich = "";
    ngayGiaoDich = "";
    donGia = 0;
    dienTich = 0;
}

bool laNgayhople(const std::string& s)
{
    if(s.length() != 10) return false; //kiem do dai 10 ky tu

    if(s[2] != '/' || s[5] != '/') return false;

    for(int i =0; i < 10;i++)
    {
        if(i == 2 || i == 5)continue;
        if(!isdigit(s[i])) return false;
    }

    int d = std::stoi(s.substr(0,2));
    int m = std::stoi(s.substr(3,2));
    int y = std::stoi(s.substr(6,4));

    //Lay ngay thang nam hien tai
    std::time_t t = std::time(nullptr);
    std::tm* n = std::localtime(&t);

    int y_n = n->tm_year + 1900;
    int m_n = n->tm_mon + 1;
    int d_n = n->tm_mday;

    if(y > y_n) return false;

    //Khong vuot qua ngay hien tai
    if(y == y_n)
    {
        if(m > m_n)return false;
        if(m == m_n && d > d_n) return false;
    }

    if(m < 1 || m > 12) return false;

    int d_inmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        d_inmonth[2] = 29;
    }

    if(d < 1 || d > d_inmonth[m]) return false;

    return true;
}

//Giao dich
istream& Trade::Nhap(istream& is)
{
    cout<< "Nhap ma giao dich: "; is>> maGiaoDich;
    cout<< "Nhap ngay giao dich: ";
    while(true)
    {
        is>> ngayGiaoDich;
        if(laNgayhople(ngayGiaoDich)) break;
        cerr<< "Loi!Vui long nhap lai: ";
    }
    cout<< "Nhap don gia: "; is>> donGia;
    cout<< "Nhap dien tich: "; is>> dienTich;

    return is;
}

ostream& Trade::Xuat(ostream& os) const
{
    os<< "Ma giao dich: "<< left<< setw(20)<< maGiaoDich
      << " | Ngay giao dich: "<< setw(12)<< ngayGiaoDich
      << " | Don gia: "<< donGia<< " | Dien tich: "<< dienTich;

    return os;
}

//Giao dich dat
istream& Trade_e::Nhap(istream& is)
{
    Trade::Nhap(is);
    cout<< "Nhap loai dat(A, B, C): "; is>> loaiDat;

    return is;
}

double Trade_e::tinhThanhtien() const
{
    if(loaiDat == "A" || loaiDat == "a")
        return dienTich * donGia * 1.5;
    return dienTich * donGia;
}

ostream& Trade_e::Xuat(ostream& os) const
{
    cout<< "Loai Giao dich: Dat"<< endl;
    Trade::Xuat(os);
    os<< " | Loai dat: "<< loaiDat
      << " | Thanh tien: "<< tinhThanhtien()<< endl;

      return os;
}

//Giao dich nha pho
istream& Trade_h::Nhap(istream& is)
{
    Trade::Nhap(is);

    while(true)
    {
        cerr<< "Nhap loai nha (cao cap/thuong): ";
        getline(is>> ws,loaiNha);
        if(loaiNha == "cao cap" || loaiNha == "thuong")break;
    }

    cout<< "Nhap dia chi: ";
    getline(is>> ws, diaChi);

    return is;
}

double Trade_h::tinhThanhtien() const
{
    if(loaiNha == "cao cap") return dienTich * donGia;
    return dienTich * donGia * (90/100);
}

ostream& Trade_h::Xuat(ostream& os) const
{
    cout<< "Loai Giao dich: Nha Pho"<< endl;
    Trade::Xuat(os);
    os<< " | Loai nha: "<< loaiNha
      << " | Dia chi: "<< diaChi
      << " | Thanh tien: "<< tinhThanhtien()<< endl;

      return os;
}

//Giao dich can ho chung cu
istream& Trade_a::Nhap(istream& is)
{
    Trade::Nhap(is);

    cout<< "Nhap ma can: ";
    getline(is>> ws, maCan);

    cout<< "Nhap vi tri tang (>0): ";
    while(true)
    {
        is>> vitriTang;
        if(vitriTang > 0) break;
        cerr<< "Moi nhap lai vi tri tang (>0): ";
    }

    return is;
}

double Trade_a::tinhThanhtien() const
{
    if(vitriTang == 1) return dienTich * donGia * 2;
    if(vitriTang >= 15) return dienTich * donGia * 1.2;

    return dienTich * donGia;
}

ostream& Trade_a::Xuat(ostream& os) const
{
    cout<< "Loai giao dich: Can ho chung cu"<< endl;
    Trade::Xuat(os);
    os<< " | Ma can: "<< maCan
      << " | Vi tri tang: "<< vitriTang
      << " | Thanh tien: "<< tinhThanhtien()<< endl;

    return os;
}
