#ifndef CDATHUC_H
#define CDATHUC_H

class cdt {
private:
    int bac;
    double *a; // Mảng lưu hệ số
public:
    cdt();
    cdt(int n);
    cdt(const cdt &other);            // Copy Constructor (Quan trọng)
    ~cdt();

    cdt& operator=(const cdt &other); // Operator= (Quan trọng)

    void Nhap();
    void Xuat();
    double GiaTri(double x);
    cdt Cong(const cdt &b);
    cdt Tru(const cdt &b);
};

#endif
