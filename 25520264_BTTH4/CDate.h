#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate
{
    private:
        int d,m,y;
        bool y_Nhuan(int y)const;// kiem nam nhuan
        int d_inmonth(int m, int y)const;// tinh so ngay trong thang
        long d_tong() const; // chuyen date sang days
        CDate ChuanHoa(long t);//chuan hoa ngay thang nam

    public:
        //Constructor
        CDate(int d = 1, int m = 1, int y = 1);

        //Nhap/Xuat
        friend std::istream& operator>> (std::istream& is,CDate& a);
        friend std::ostream& operator<< (std::ostream& os,const CDate& a);

        //Phep toan
        CDate operator + (int a);
        CDate operator - (int a);

        //Tang/Giam 1
        CDate& operator ++();
        CDate operator ++(int);
        CDate& operator --();
        CDate operator --(int);

        //Khoang cach 2 CDate tinh bang ngay
        long operator -(const CDate& a) const;
};

#endif // CDATE_H
