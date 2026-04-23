#include "DIEM.h"
#include <iostream>
#include <limits>

using namespace std;

DIEM::DIEM()
{
        dx = 0;
        dy = 0;
}

DIEM::DIEM(double a, double b)
{
    dx = a;
    dy = b;
}

DIEM::DIEM(const DIEM &a)
{
    dx = a.dx;
    dy = a.dy;
}

void DIEM::Nhap()
{
    while(true)
    {
        cout<< endl;

        cout<< "Nhap x:";
        cin>> dx;

        cout<< "Nhap y:";
        cin>> dy;

        if(cin.fail())
        {
            cout<< endl;
            cout<< "Nhap sai! Vui long nhap lai. \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else
            break;
    }
}

void DIEM::Xuat()
{
    cout<< dx<< dy;
}
