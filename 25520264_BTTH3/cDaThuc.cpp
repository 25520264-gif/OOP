#include "cDaThuc.h"
#include <iostream>
#include <cmath>
using namespace std;

cdt::cdt() {
    bac = 0;
    a = new double[1];
    a[0] = 0;
}

cdt::cdt(int n) {
    bac = n;
    a = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        a[i] = 0;
}

cdt::~cdt() {
    delete[] a;
}

void cdt::Nhap() {
    cout << "Nhap bac da thuc: ";
    cin >> bac;

    delete[] a;
    a = new double[bac + 1];

    for (int i = bac; i >= 0; i--) {
        cout << "Nhap he so a[" << i << "]: ";
        cin >> a[i];
    }
}

cdt::cdt(const cdt &other) {
    bac = other.bac;
    a = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        a[i] = other.a[i];
    }
}

cdt& cdt::operator=(const cdt &other) {
    if (this != &other) { // Tránh tự gán chính mình
        delete[] a;       // Giải phóng vùng nhớ cũ

        bac = other.bac;
        a = new double[bac + 1]; // Cấp phát vùng nhớ mới
        for (int i = 0; i <= bac; i++) {
            a[i] = other.a[i];   // Sao chép dữ liệu
        }
    }
    return *this;
}

void cdt::Xuat() {
    for (int i = bac; i >= 0; i--) {
        if (a[i] != 0) {
            cout << a[i];
            if (i > 0) cout << "x^" << i;
            if (i > 0) cout << " + ";
        }
    }
    cout << endl;
}

double cdt::GiaTri(double x) {
    double s = 0;
    for (int i = 0; i <= bac; i++) {
        s += a[i] * pow(x, i);
    }
    return s;
}

cdt cdt::Cong(const cdt &b) {
    int maxBac = max(bac, b.bac);
    cdt kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double hs1 = (i <= bac) ? a[i] : 0;
        double hs2 = (i <= b.bac) ? b.a[i] : 0;
        kq.a[i] = hs1 + hs2;
    }

    return kq;
}

cdt cdt::Tru(const cdt &b) {
    int maxBac = max(bac, b.bac);
    cdt kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double hs1 = (i <= bac) ? a[i] : 0;
        double hs2 = (i <= b.bac) ? b.a[i] : 0;
        kq.a[i] = hs1 - hs2;
    }

    return kq;
}
