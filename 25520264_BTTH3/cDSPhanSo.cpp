#include "cDSPHanSo.h"
#include <algorithm>
#include <cmath>

void ds_p::Nhap() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    ds.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Phan so " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void ds_p::Xuat() {
    for (auto x : ds) {
        x.Xuat();
        cout << " ";
    }
    cout << endl;
}

PhanSo ds_p::Tong() {
    PhanSo sum;
    for (auto x : ds)
        sum = sum + x;
    return sum;
}

PhanSo ds_p::LonNhat() {
    PhanSo max = ds[0];
    for (auto x : ds)
        if (x > max) max = x;
    return max;
}

PhanSo ds_p::NhoNhat() {
    PhanSo min = ds[0];
    for (auto x : ds)
        if (x < min) min = x;
    return min;
}

bool ds_p::LaNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

PhanSo ds_p::TuNguyenToLonNhat() {
    PhanSo kq;
    int maxTu = -1;

    for (auto x : ds) {
        int t = x.getTu();
        if (LaNguyenTo(t) && t > maxTu) {
            maxTu = t;
            kq = x;
        }
    }
    return kq;
}

void ds_p::TangDan() {
    sort(ds.begin(), ds.end(), [](PhanSo a, PhanSo b) {
        return a < b;
    });
}

void ds_p::GiamDan() {
    sort(ds.begin(), ds.end(), [](PhanSo a, PhanSo b) {
        return a > b;
    });
}
