#ifndef SOPHUC_H
#define SOPHUC_H


class SoPhuc
{
    public:
        void Nhap();
        void Xuat();

        SoPhuc Tong(SoPhuc sp);
        SoPhuc Hieu(SoPhuc sp);
        SoPhuc Tich(SoPhuc sp);
        SoPhuc Thuong(SoPhuc sp);

    private:
        double iThuc;
        double iAo;
};

#endif // SOPHUC_H
