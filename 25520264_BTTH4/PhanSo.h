#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>


class PhanSo
{
    private:
        double itu, imau;
    public:
        //Constructor
         PhanSo(double t = 0, double m = 1);

         //Input/Output
         friend std::istream& operator>>(std::istream& is, PhanSo& ps);
         friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);

         //Phep toan
         PhanSo operator + (const PhanSo& a)const;
         PhanSo operator - (const PhanSo& a)const;
         PhanSo operator * (const PhanSo& a)const;
         PhanSo operator / (const PhanSo& a)const;

         //So sanh
         double GiaTri()const;

         bool operator == (const PhanSo& a);
         bool operator > (const PhanSo& a);
         bool operator < (const PhanSo& a);

};

#endif // PHANSO_H
