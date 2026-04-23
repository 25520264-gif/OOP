#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

cArr::cArr() {
    a = NULL;
    n = 0;
}

cArr::~cArr() {
    delete[] a;
}

void cArr::TaoNgauNhien(int size) {
    n = size;
    a = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void cArr::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int cArr::DemX(int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) dem++;
    }
    return dem;
}

bool cArr::KiemTraTang() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int cArr::TimLeNhoNhat() {
    int minLe = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < minLe) {
            minLe = a[i];
            found = true;
        }
    }

    return found ? minLe : -1;
}

bool cArr::isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int cArr::TimNTLonNhat() {
    int maxNT = -1;

    for (int i = 0; i < n; i++) {
        if (isPrime(a[i]) && a[i] > maxNT) {
            maxNT = a[i];
        }
    }

    return maxNT;
}

void cArr::SapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void cArr::SapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
