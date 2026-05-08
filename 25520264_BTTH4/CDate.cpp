#include "CDate.h"
#include <iostream>
#include <iomanip>

//Constructor
CDate::CDate(int d, int m, int y):
    d(d), m(m), y(y){}

//Nhap/Xuat
std::istream& operator>> (std::istream& is, CDate& a)
{
    std::cout<< "Nhap ngay: ";is>> a.d;
    std::cout<< "\nNhap thang: ";is>> a.m;
    std::cout<< "\nNhap nam: "; is>> a.y;

    return is;
}

std::ostream& operator<< (std::ostream& os, const CDate& a)
{
    os<< std::setfill('0')<< std::setw(2)<< a.d<< "/"
      << std::setfill('0')<< std::setw(2)<< a.m<< "/"
      << std::setfill('0')<< std::setw(2)<< a.y<< std::endl;

      return os;
}

bool CDate::y_Nhuan(int y)const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

}

int CDate::d_inmonth(int m, int y)const
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(m == 2 && y_Nhuan(y)) return 29;
    return days[m];
}

long CDate::d_tong() const
{
    long t = d; //tong = day
    for(int i = 1; i < y; ++i) t += (y_Nhuan(i)? 366 : 365);
    for(int i = 1; i < m; ++i) t += d_inmonth(i,y);
    return t;
}

CDate CDate::ChuanHoa(long t)
{
    int year = 1, month = 1;
    int d_year = y_Nhuan(y) ? 366 : 365;

    while (t > d_year)
    {
        t -= d_year;
        year++;
    }

    while(t > d_inmonth(m,y))
    {
        t -= d_inmonth(m,y);
        month++;
    }
    return CDate(t,month,year);
}

CDate CDate::operator+(int a)
{
    return ChuanHoa(d_tong() + a);
}

CDate CDate::operator-(int a)
{
    return ChuanHoa(d_tong() - a);
}

long CDate::operator-(const CDate& a) const
{
    return d_tong() - a.d_tong();
}

CDate& CDate::operator++()
{
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int)
{
    CDate temp = *this;
    ++(*this);
    return temp;
}

CDate& CDate::operator--()
{
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int)
{
    CDate temp = *this;
    --(*this);
    return temp;
}
