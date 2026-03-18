#include <iostream>
using namespace std;

int main()
{
    int a, b, m ,n;
    cout<< "Nhap tu 1: ";cin>> a;
    cout<< "Nhap mau 1: ";
    while( cin>> b)
    {
        if(b != 0) break;
        cout<< "Nhap mau 1: ";
    }

    cout<< "Nhap tu 2: ";cin>> n;
    cout<< "Nhap mau 2: ";
    while( cin>> m)
    {
        if(m != 0) break;
        cout<< "Nhap mau 2: ";
    }

    int t;
    cout<< " 1. Tong  2.Hieu  3.Tich  4.Thuong"<< endl;
    cout<< "Chon: ";cin>> t;

    if(b == n)
    {
        switch(t)
        {
            case 1: cout<< "Ket qua: "<< a+n<< "/"<< b;break;
            case 2: cout<< "Ket qua: "<< a-n<< "/"<< b;break;
            case 3: cout<< "Ket qua: "<< a*n<< "/"<< b*m;break;
            case 4: cout<< "Ket qua: "<< a*m<< "/"<< b*n;break;
        }
    }

    else
    {
        switch(t)
        {
            case 1: cout<< "Ket qua: "<< a*m + n*b<< "/"<< b*m;break;
            case 2: cout<< "Ket qua: "<< a*m - n*b<< "/"<< b*m;break;
            case 3: cout<< "Ket qua: "<< a*n<< "/"<< b*m;break;
            case 4: cout<< "Ket qua: "<< a*m<< "/"<< b*n;break;
        }
    }
}
