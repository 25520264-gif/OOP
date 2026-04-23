#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <iostream>
using namespace std;

class cNhanVienSX
{
private:
    string ma, hoten;
    int ngay, thang, nam;
    int soSP;
    double donGia;

public:
    cNhanVienSX();
    cNhanVienSX(string, string, int, int, int, int, double);

    void Nhap();
    void Xuat();

    double TinhLuong();
    int GetTuoi();
};

#endif
