#include "SoPhuc.h"
#include <iostream>
using namespace std;

void SoPhuc::Nhap()
{
    cout<< "Nhap so thuc: ";
    cin>> iThuc;

    cout<< "Nhap so Ao: ";
    cin>> iAo;
}

void SoPhuc::Xuat()
{
    cout<< iThuc<< " + "<< iAo<< "i";
}

SoPhuc SoPhuc::Tong(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

SoPhuc SoPhuc::Hieu(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

SoPhuc SoPhuc::Tich(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

SoPhuc SoPhuc::Thuong(SoPhuc sp)
{
    SoPhuc kq;
    double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;

    //Kiem tra mau khac 0
    if (mau == 0)
        {
            cout << "\nKhong the chia cho 0!";
            kq.iThuc = 0;
            kq.iAo = 0;
            return kq;
        }

    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo)/mau;
    kq.iAo = (iThuc * sp.iAo - iAo * sp.iThuc)/mau;
    return kq;
}
