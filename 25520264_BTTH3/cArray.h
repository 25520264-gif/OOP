#ifndef CARRAY_H
#define CARRAY_H

class cArr {
private:
    int *a;
    int n;

public:
    cArr();
    ~cArr();

    void TaoNgauNhien(int size);
    void Xuat();

    int DemX(int x);
    bool KiemTraTang();

    int TimLeNhoNhat();
    int TimNTLonNhat();

    void SapXepTang();
    void SapXepGiam();

    bool isPrime(int x);
};

#endif
