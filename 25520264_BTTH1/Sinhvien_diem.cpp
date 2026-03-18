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
    cout<< "Nhap ho ten: ";    // Nhap ho ten: Duong Tuan Dat
    cin.getline(sv.s, mx);

    cout<< "Nhap diem toan: ";cin>> sv.t;    // Nhap diem toan: 10
    cout<< "Nhap diem van: ";cin>> sv.v;     // Nhap diem van: 9.8

    double dtb = (sv.t+sv.v)/2;    // dtb = (10 + 9.8)/2 = 9.9 

    cout<< "Ho ten sinh vien: ";    
    int i =0;
    while(sv.s[i] != '\0')    // in Duong Tuan Dat
    {
        cout<< sv.s[i];
        i++;
    }
    cout<< endl;

    cout<< "Diem trung binh: "<< fixed<< setprecision(2)<< dtb; // vDiem trung binh: 9.90 

}
