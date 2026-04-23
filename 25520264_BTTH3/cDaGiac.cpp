#include "cDaGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

cdg::cdg() {
    n = 0;
}

void cdg::Nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void cdg::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "\nDiem " << i + 1 << ": \n";
        ds[i].Xuat();
    }
}

// khoảng cách 2 điểm
double KhoangCach(DIEM a, DIEM b) {
    return sqrt(pow(a.dx - b.dx, 2) + pow(a.dy - b.dy, 2));
}

double cdg::TinhChuVi() {
    double cv = 0;
    for (int i = 0; i < n; i++) {
        cv += KhoangCach(ds[i], ds[(i + 1) % n]);
    }
    return cv;
}

// Shoelace formula
double cdg::TinhDienTich() {
    double s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += ds[i].dx * ds[j].dy - ds[j].dx * ds[i].dy;
    }
    return abs(s) / 2.0;
}

void cdg::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        ds[i].dx += dx;
        ds[i].dy += dy;
    }
}

void cdg::PhongTo(double k) {
    for (int i = 0; i < n; i++) {
        ds[i].dx *= k;
        ds[i].dy *= k;
    }
}

void cdg::ThuNho(double k) {
    for (int i = 0; i < n; i++) {
        ds[i].dx /= k;
        ds[i].dy /= k;
    }
}

void cdg::Quay(double goc) {
    for (int i = 0; i < n; i++) {
        double x = ds[i].dx;
        double y = ds[i].dy;

        ds[i].dx = x * cos(goc) - y * sin(goc);
        ds[i].dy = x * sin(goc) + y * cos(goc);
    }
}
