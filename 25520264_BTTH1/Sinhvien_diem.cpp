#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

#define mx 400

struct Sinh_vien
{
    char s[mx];
    double t;
    double v;
};

int main()
{
    Sinh_vien sv;
    cout<< "Nhap ho ten: ";
    cin.getline(sv.s, mx);

    cout<< "Nhap diem toan: ";cin>> sv.t;
    cout<< "Nhap diem van: ";cin>> sv.v;

    double dtb = (sv.t+sv.v)/2;

    cout<< "Ho ten sinh vien: ";
    int i =0;
    while(sv.s[i] != '\0')
    {
        cout<< sv.s[i];
        i++;
    }
    cout<< endl;

    cout<< "Diem trung binh: "<< fixed<< setprecision(2)<< dtb;

}
