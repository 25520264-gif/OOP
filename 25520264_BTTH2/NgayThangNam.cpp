#include <iostream>
#include "NgayThangNam.h"
using namespace std;

bool Kiem_SaiN(int a,int b, int c) //Kiem thu nhap dung ngay thang nam
{
    if(a >31 || b >12)return true;
    if(b == 2 && c % 4 == 0 && a > 29) return true;
    if(b == 2 && c % 4 != 0 && a > 28) return true;

    return false;
}

void dmy::Nhap()
{
    do
    {
        cout<< "Nhap ngay hom nay: ";
        cin>> iNgay;

        cout<< "Nhap thang hom nay: ";
        cin>> iThang;

        cout<< "Nhap nam hom nay: ";
        cin>> iNam;
    }while(Kiem_SaiN(iNgay,iThang,iNam));
}

void dmy::Xuat()
{
    cout<< iNgay<< "/"<< iThang<< "/"<< iNam;
}

void dmy::NgayThangNamTiepTheo()
{
    int songay;
    switch(iThang)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11: songay =31;break;
        case 4:
        case 6:
        case 8:
        case 10:
        case 12: songay =30;break;
        default:
            {
                if(iNam % 4 == 0)songay =29;
                else songay = 28;
            }
    }
    iNgay++;
    if(iNgay > songay)
    {
        iNgay = 1;
        iThang++;
        if(iThang > 12)
        {
            iThang =1;
            iNam++;
        }
    }
}
