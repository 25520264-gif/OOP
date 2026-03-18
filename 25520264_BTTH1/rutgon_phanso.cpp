#include <iostream>
using namespace std;

int main()
{
    int t, m;
    cout<< "Nhap tu: ";  cin>> t;
    cout<< "Nhap mau: ";

    while( cin>> m)
    {
        if(m != 0) break;
        cout<< "Nhap mau: ";
    }

    int s =0;
    for(int i =1;i <= min(m,t );i++)
    {
        if(t%i == 0 && m%i == 0)
        {
            s = i;
        }
    }

    int y = t/s;
    int n = m/s;
    y%n == 0?cout<< "Ket qua: "<< y/n:cout<< "Ket qua: "<< y<< "/"<< n;

    return 0;
}
