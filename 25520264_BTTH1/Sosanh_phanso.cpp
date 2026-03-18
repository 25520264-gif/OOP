#include <iostream>
using namespace std;

int main()
{
    int a, b, m ,n;
    cout<< "Nhap tu 1: ";cin>> a;    // Nhap 6
    cout<< "Nhap mau 1: ";

    // Kiem mau khac 0
    while( cin>> b)    // Nhap 9
    {
        if(b != 0) break;
        cout<< "Nhap mau 1: ";
    }

    cout<< "Nhap tu 2: ";cin>> n;    // Nhap 5
    cout<< "Nhap mau 2: ";
    while( cin>> m)    //Nhap 3
    {
        if(m != 0) break;
        cout<< "Nhap mau 2: ";
    }

    // (a/b) > (n/m) <=> (a*m) > (n*b)
    if((a*m) > (n*b)) 
        cout<< "Ket qua: "<< a<< "/"<< b;
    else    // (6*3) < (5*9)
        cout<< "Ket qua: "<< n<< "/"<< m;     // Ket qua: 5/3
    return 0;
}
