#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include <iostream>
using namespace std;

class cNhanVienVP
{
private:
    string ma, hoten;
    int ngay, thang, nam;
    double luong;

public:
    // constructor
    cNhanVienVP();
    cNhanVienVP(string, string, int, int, int, double);

    // method
    void Nhap();
    void Xuat();
    double GetLuong();
    int GetTuoi();
};

#endif
