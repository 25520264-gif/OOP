#include "PhanSo.h"
#include <iostream>

//Constructor
PhanSo::PhanSo(double t, double m)
{
    itu = t;
    imau = m;
}

//Input/Output
std::istream& operator>>(std::istream& is, PhanSo& ps)
{
    std::cout<< "Nhap tu: ";
    is>> ps.itu;

    do
    {
        std::cout<< "Nhap mau: ";
        is>> ps.imau;
        if(ps.imau == 0)
            std::cerr<< "Loi!Mau so khong the bang 0, vui long nhap lai!\n";
    }while(ps.imau == 0);

    return is;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps)
{
    if(ps.imau > 0)
        os<< ps.itu<< "/"<< ps.imau;
    else
        os<< -ps.itu<< "/"<< -ps.imau;

    return os;
}

//Phep toan
PhanSo PhanSo::operator + (const PhanSo& a)const{
    PhanSo tong;

    tong.itu = this->itu * a.imau + a.itu * this->imau;
    tong.imau = this->imau * a.imau;

    return tong;
}

PhanSo PhanSo::operator - (const PhanSo& a)const{
    PhanSo hieu;

    hieu.itu = this->itu * a.imau - a.itu * this->imau;
    hieu.imau = this->imau * a.imau;

    return hieu;
}

PhanSo PhanSo::operator * (const PhanSo& a)const{
    PhanSo tich;

    tich.itu = itu * a.itu;
    tich.imau = imau * a.imau;

    return tich;
}

PhanSo PhanSo::operator / (const PhanSo& a)const{
    PhanSo thuong;

    thuong.itu = itu * a.imau;
    thuong.imau = imau * a.itu;

    return thuong;
}

//So sanh
double PhanSo::GiaTri() const
{
    return (double) itu/imau;
}

bool PhanSo::operator == (const PhanSo& a)
{
    return this->GiaTri() == a.GiaTri();
}

bool PhanSo::operator > (const PhanSo& a)
{
    return this->GiaTri() > a.GiaTri();
}

bool PhanSo::operator < (const PhanSo& a)
{
    return this->GiaTri() < a.GiaTri();
}


