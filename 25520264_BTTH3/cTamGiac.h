#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "DIEM.h"
#include <string>
using namespace std;

class ctg
{
    public:
        void Nhap();
        void Xuat();
        ctg() {}
        ctg(DIEM a,DIEM b, DIEM c) {}

        bool Hople();

        double DoDai(DIEM P, DIEM Q);
        string PhanLoai();
        double ChuVi();
        double DienTich();

        void TinhTien(double dx, double dy);
        void Quay(double goc);
        void QuayQuanhDiem(DIEM O, double goc);
        void PhongTo(double k);
        void ThuNho(double k);

    private:
        DIEM A,B,C;
};

#endif // CTAMGIAC_H
