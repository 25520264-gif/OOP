#include "Nvien.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>

typedef long long ll;

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

std::istream& Nvien::Nhap(std::istream& is)
{
    std::cout<< "Nhap ho ten: ";
    std::getline(is>> std::ws, HoTen);
    std::cout<< "Nhap ngay sinh(dd/mm/yyyy): ";
    while(true)
    {
        is>> NgaySinh;
        if(laNgayhople(NgaySinh))
           break;
        std::cerr<< "Khong hop le!Moi nhap lai: ";
    }
    return is;
}

std::ostream& Nvien::Xuat(std::ostream& os) const
{
    os<< "Ho ten: "<< std::left<< std::setw(20)<< HoTen
             << " | Ngay sinh: "<< std::setw(12)<< NgaySinh
             << " | Luong: "<< TinhLuong();

    return os;
}

int Nvien::TinhTuoi()
{
    int d = std::stoi(NgaySinh.substr(0,2));
    int m = std::stoi(NgaySinh.substr(3,2));
    int y = std::stoi(NgaySinh.substr(6,4));

    return (long long) y * 10000 + m * 100 + d;
}

std::istream& Nvien_SX::Nhap(std::istream& is)
{
    Nvien::Nhap(is);
    std::cout<< "Nhap luong can ban: ";
    is>> luongcanban;
    std::cout<< "Nhap so san pham: ";
    is>> sosanpham;
    return is;
}

ll Nvien_SX::TinhLuong() const
{
    return luongcanban + (sosanpham * 5000);
}

std::ostream& Nvien_SX::Xuat(std::ostream& os) const
{
    os<< "Loai: (SanXuat)"<< std::endl;
    Nvien::Xuat(os);
    os<< std::endl;

    return os;
}

std::istream& Nvien_VP::Nhap(std::istream& is)
{
    Nvien::Nhap(is);
    std::cout<< "Nhap so ngay lam viec: ";
    is>> soNgayLamViec;

    return is;
}

ll Nvien_VP::TinhLuong() const
{
    return soNgayLamViec * 100000;
}

std::ostream& Nvien_VP::Xuat(std::ostream& os) const
{
    os<< "Loai: (VanPhong)"<< std::endl;
    Nvien::Xuat(os);
    os<< std::endl;

    return os;
}
