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

    if((a*m) > (n*b))
        cout<< "Ket qua: "<< a<< "/"<< b;
    else
        cout<< "Ket qua: "<< n<< "/"<< m;

}
