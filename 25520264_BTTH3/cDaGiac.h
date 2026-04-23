#pragma once
#include <vector>
#include "DIEM.h"
using namespace std;

class cdg {
private:
    int n;
    vector<DIEM> ds;

public:
    cdg();

    void Nhap();
    void Xuat();

    double TinhChuVi();
    double TinhDienTich();

    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double goc); // radian
};
