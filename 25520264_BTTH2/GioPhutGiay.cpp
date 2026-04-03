#include "GioPhutGiay.h"
#include <iostream>
using namespace std;

bool Kiem_SaiG(int a,int b,int c)
{
    if(a > 24)return true;
    if(b > 60 || c > 60)return true;

    return false;
}

void gpg::Nhap()
{
    do
    {
        cout<< "Nhap gio hien tai: ";
        cin>> iGio;

        cout<< "Nhap phut hien tai: ";
        cin>> iPhut;

        cout<< "Nhap giay hien tai: ";
        cin>> iGiay;
    }while(Kiem_SaiG(iGio,iPhut,iGiay));
}

void gpg::Xuat()
{
    cout<< "Ke tiep la: "<< iGio<< " gio "<< iPhut<< " phut "<< iGiay<< " giay";
}

void gpg::TinhCongThemGiay()
{
    iGiay++;
    if(iGiay >= 60)
    {
        iGiay = 0;
        iPhut++;
        if(iPhut >= 60)
        {
            iPhut = 0;
            iGio++;
            if(iGio >=24)iGio = 0;
        }
    }
}
