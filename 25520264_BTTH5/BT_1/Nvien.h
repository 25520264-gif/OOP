#ifndef NVIEN_H
#define NVIEN_H

#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

class Nvien
{
    protected:
        std::string HoTen, NgaySinh;
        ll luong;
    public:
        //Nhap/Xuat
        friend std::istream& operator>> (std::istream& is, Nvien& a)
        {
            return a.Nhap(is);
        }
        virtual std::istream& Nhap(std::istream& is);

        friend std::ostream& operator<< (std::ostream& os, const Nvien& a)
        {
            return a.Xuat(os);
        }
        virtual std::ostream& Xuat(std::ostream& os)const;

        //Tinh luong
        virtual ll TinhLuong() const = 0;

        //Ham get
        std::string getHoTen( )
        {
            return HoTen;
        }
        int TinhTuoi();

        virtual ~Nvien() {}
};

class Nvien_SX : public Nvien
{
    private:
        ll luongcanban;
        int sosanpham;
    public:
        std::istream& Nhap(std::istream& is) override;
        std::ostream& Xuat(std::ostream& os) const override;
        ll TinhLuong() const override;
};

class Nvien_VP : public Nvien
{
    private:
        int soNgayLamViec;
    public:
        std::istream& Nhap(std::istream& is) override;
        std::ostream& Xuat(std::ostream& os) const override;
        ll TinhLuong() const override;
};

#endif // NVIEN_H
