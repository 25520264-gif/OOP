#ifndef DIEM_H
#define DIEM_H

class DIEM
{
    public:
        double dx,dy;

        DIEM();
        DIEM(double a, double b);
        DIEM(const DIEM &a);
        void Nhap();
        void Xuat();
};

#endif // DIEM_H
