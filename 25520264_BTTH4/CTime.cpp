#include "CTime.h"
#include <iostream>
#include <iomanip>

CTime::CTime(int h,int m,int s) :
    h(h), m(m), s(s)
{
    ChuanHoa();
}

void CTime::ChuanHoa()
{
    long tong = h * 3600 + m * 60 + s;//chuyen tat ca thanh giay

    tong = (tong % 86400 + 86400) % 86400;

    h = (tong / 3600)% 24;
    m = (tong % 3600)/ 60;
    s = tong % 60;
}

std::istream& operator>>(std::istream& is,CTime& t)
{
    std::cout<< "Nhap gio: ";is>> t.h;
    std::cout<< "Nhap phut: ";is>> t.m;
    std::cout<< "Nhap giay: ";is>> t.s;
    t.ChuanHoa();
    std::cout<< std::endl;

    return is;
}

std::ostream& operator<<(std::ostream& os, const CTime& t)
{
    os<< std::setfill('0')<< std::setw(2)<< t.h<< ":"
      << std::setfill('0')<< std::setw(2)<< t.m<< ":"
      << std::setfill('0')<< std::setw(2)<< t.s<< std::endl;

    return os;
}

CTime CTime::operator+(int s)
{
    return CTime(h,m,this->s + s);
}

CTime CTime::operator-(int s)
{
    return CTime(h,m,this->s - s);
}

CTime& CTime::operator++()
{
    s++;
    ChuanHoa();
    return *this;
}

CTime CTime::operator++(int)
{
    CTime temp = *this;
    ++(*this);
    return temp;
}

CTime& CTime::operator--()
{
    s--;
    ChuanHoa();
    return *this;
}

CTime CTime::operator--(int)
{
    CTime temp = *this;
    --(*this);
    return temp;
}
