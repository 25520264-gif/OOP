#include <iostream>
using namespace std;

int main()
{
    int t, m;
    cout<< "Nhap tu: ";  cin>> t;    // Nhap 6
    cout<< "Nhap mau: ";             

    // Kiem mau khac 0
    while( cin>> m)    // Nhap 9
    {
        if(m != 0) break;
        cout<< "Nhap mau: ";    
    }

    int s =0;
    for(int i =1;i <= min(m,t );i++) // Tim uoc chung lon nhat
    {
        if(t%i == 0 && m%i == 0)
        {
            s = i;
        }
    }

    // Rut gon tu ma
    int y = t/s;
    int n = m/s;

    // Neu la so nguyen --> in y/n, neu khong in y '/' n
    y%n == 0?cout<< "Ket qua: "<< y/n:cout<< "Ket qua: "<< y<< "/"<< n;    // Ket qua: 2/3

    return 0;
}
