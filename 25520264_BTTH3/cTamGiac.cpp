#include "cTamGiac.h"
#include "DIEM.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ctg::Nhap()
{
   cout<< "Nhap diem A: ";
   A.Nhap();

   cout<< "Nhap diem B: ";
   B.Nhap();

   cout<< "Nhap diem C: ";
   C.Nhap();
}

void ctg::Xuat()
{
    cout<< "A("<< A.dx<< ","<< A.dy<< ")"<< endl;
    cout<< "B("<< B.dx<< ","<< B.dy<< ")"<< endl;
    cout<< "C("<< C.dx<< ","<< C.dy<< ")"<< endl;
}

// kiem tra hợp lệ
bool ctg::Hople()
{
    double S= 0.5 * abs(A.dx * (B.dy - C.dy)
                        + B.dx * (C.dy - A.dy)
                        + C.dx * (A.dy - B.dy));

    return (S != 0);
}

//Tinh do dai
double ctg::DoDai(DIEM P, DIEM Q)
{
    double PQ;
    PQ = sqrt(pow(Q.dx - P.dx,2) + pow(Q.dy - P.dy,2));
    return PQ;
}

//Phan loai tam giac
string ctg::PhanLoai()
{
    double AB, BC, AC;
    AB = DoDai(A,B);
    AC = DoDai(A,C);
    BC = DoDai(B,C);

    if(!Hople()) return "Khong phai tam giac";

    const double eps = 1e-6;

    //Kiem deu
    if (fabs(AB - AC) < eps && fabs(AB - BC) < eps) return "Deu";

    //Kiem vuong
    bool laVuong = (fabs(AB*AB + BC*BC - AC*AC) < eps ||
                    fabs(AB*AB + AC*AC - BC*BC) < eps ||
                    fabs(BC*BC + AC*AC - AB*AB) < eps);

    // Kiem vuong/vuong can
    if (fabs(AB - AC) < eps || fabs(AB - BC) < eps || fabs(BC - AC) < eps)
    {
        if(laVuong)
            return "Vuong can";
        return "Can";
    }
    if(laVuong)
            return "Vuong";

    return "Thuong";
}

//Tinh Chu vi
double ctg::ChuVi()
{
    double c, AB, BC, AC;
    AB = DoDai(A,B);
    AC = DoDai(A,C);
    BC = DoDai(B,C);

    c = AB + BC +AC;

    return c;
}

//Tinh Dien tich
double ctg::DienTich()
{
    double S = 0.5 * abs(A.dx * (B.dy - C.dy)
                        + B.dx * (C.dy - A.dy)
                        + C.dx * (A.dy - B.dy));

    return S;
}

void ctg::TinhTien(double dx, double dy) {
    A.dx += dx; A.dy += dy;
    B.dx += dx; B.dy += dy;
    C.dx += dx; C.dy += dy;
}

void ctg::Quay(double gocDo)
{
    double rad = gocDo * acos(-1)/180;
    auto Quay1Diem = [&](DIEM &P)
    {
        double x = P.dx * cos(rad) - P.dy * sin(rad);
        double y = P.dx * sin(rad) + P.dy * cos(rad);
    };

    Quay1Diem(A);
    Quay1Diem(B);
    Quay1Diem(C);
}

void ctg::PhongTo(double k) {
    A.dx *= k; A.dy *= k;
    B.dx *= k; B.dy *= k;
    C.dx *= k; C.dy *= k;
}

void ctg::ThuNho(double k) {
    if (k != 0) {
        A.dx /= k; A.dy /= k;
        B.dx /= k; B.dy /= k;
        C.dx /= k; C.dy /= k;
    }
}
