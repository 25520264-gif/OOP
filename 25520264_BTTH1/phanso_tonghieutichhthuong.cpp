#include <iostream>
using namespace std;

int main()
{
    int a, b, m ,n;
    cout<< "Nhap tu 1: ";cin>> a;    // Nhap 9
    cout<< "Nhap mau 1: ";

    // Kiem mau khac 0
    while( cin>> b)    // Nhap 6
    {
        if(b != 0) break;
        cout<< "Nhap mau 1: ";
    }

    cout<< "Nhap tu 2: ";cin>> n;    // Nhap 3
    cout<< "Nhap mau 2: ";
    while( cin>> m)    // Nhap 5
    {
        if(m != 0) break;
        cout<< "Nhap mau 2: ";
    }

    int t;
    cout<< " 1. Tong  2.Hieu  3.Tich  4.Thuong"<< endl;
    cout<< "Chon: ";cin>> t;    // Chon 2

    if(b == n)    // Neu mau bang nhau --> tu so cong tru nhau
    {
        switch(t)
        {
            case 1: cout<< "Ket qua: "<< a+n<< "/"<< b;break;
            case 2: cout<< "Ket qua: "<< a-n<< "/"<< b;break;
            case 3: cout<< "Ket qua: "<< a*n<< "/"<< b*m;break;
            case 4: cout<< "Ket qua: "<< a*m<< "/"<< b*n;break;
        }
    }

    else    // Mau so khong bang nhau
    {
        switch(t)
        {
            case 1: cout<< "Ket qua: "<< a*m + n*b<< "/"<< b*m;break;
            case 2: cout<< "Ket qua: "<< a*m - n*b<< "/"<< b*m;break;    // Ket qua: 27/30
            case 3: cout<< "Ket qua: "<< a*n<< "/"<< b*m;break;
            case 4: cout<< "Ket qua: "<< a*m<< "/"<< b*n;break;
        }
    }
}
