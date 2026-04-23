#include "PhanSo.h"
#include <cmath>

int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

PhanSo::PhanSo() {
    tu = 0;
    mau = 1;
}

PhanSo::PhanSo(int t, int m) {
    tu = t;
    mau = m == 0 ? 1 : m;
    RutGon();
}

void PhanSo::Nhap() {
    cout << "Nhap tu: "; cin >> tu;
    cout << "Nhap mau: "; cin >> mau;
    if (mau == 0) mau = 1;
    RutGon();
}

void PhanSo::Xuat() {
    cout << tu << "/" << mau;
}

void PhanSo::RutGon() {
    int g = gcd(tu, mau);
    tu /= g;
    mau /= g;
}

double PhanSo::GiaTri() const {
    return (double)tu / mau;
}

bool PhanSo::operator>(const PhanSo& other) const {
    return GiaTri() > other.GiaTri();
}

bool PhanSo::operator<(const PhanSo& other) const {
    return GiaTri() < other.GiaTri();
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    int t = tu * other.mau + other.tu * mau;
    int m = mau * other.mau;
    return PhanSo(t, m);
}

int PhanSo::getTu() const {
    return tu;
}
