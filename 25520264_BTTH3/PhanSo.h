#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    PhanSo();
    PhanSo(int t, int m);

    void Nhap();
    void Xuat();

    void RutGon();

    double GiaTri() const;

    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;

    PhanSo operator+(const PhanSo& other) const;

    int getTu() const;
};
