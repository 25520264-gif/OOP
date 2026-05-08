#ifndef CTIME_H
#define CTIME_H
#include <iostream>


class CTime
{
    private:
        int h,m,s;
        void ChuanHoa();
    public:
        //Constructor
        CTime(int h =0, int m = 0, int s = 0);

        //Nhap/Xuat
        friend std::istream& operator>>(std::istream& is, CTime& t);
        friend std::ostream& operator<<(std::ostream& os, const CTime& t);

        // Phep toan
        CTime operator + (int s);
        CTime operator - (int s);

        CTime& operator ++();
        CTime operator ++(int);
        CTime& operator --();
        CTime operator --(int);
};

#endif // CTIME_H
