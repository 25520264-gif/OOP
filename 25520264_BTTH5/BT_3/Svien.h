#ifndef SVIEN_H
#define SVIEN_H

#include <iostream>
#include <string>

using namespace std;

class Svien
{
    protected:
        int tinChi;
        double DTB;
        string MSSV, HoTen, diaChi;
    public:
        //Constructor
        Svien() :
            MSSV(""), HoTen(""), diaChi(""), tinChi(0), DTB(0.0) {};
        virtual ~Svien() = default;

        //Nhap/Xuat
        friend istream& operator>> (istream& is, Svien& a)
        {
            return a.Nhap(is);
        }
        virtual istream& Nhap(istream& is);

        friend ostream& operator<< (ostream& os, const Svien& a)
        {
            return a.Xuat(os);
        }
        virtual ostream& Xuat(ostream& os) const;

        virtual bool xetTotNghiep() const = 0;
        virtual int loai() const = 0; //1: Cao dang  2 Dai hoc

        double getDTB() const;
        string getHoTen() const;
};

class Svien_CD : public Svien
{
    private:
        double diemTN;
    public:
        Svien_CD() : Svien(), diemTN(0.0) {};

        istream& Nhap(istream& is) override;
        ostream& Xuat(ostream& os) const override;

        bool xetTotNghiep() const override;
        int loai() const override;

};

class Svien_DH : public Svien
{
    private:
        string tenLuanVan;
        double diemLuanVan;
    public:
        Svien_DH() : Svien(), tenLuanVan(""), diemLuanVan(0.0) {};

        istream& Nhap(istream& is) override;
        ostream& Xuat(ostream& os) const override;

        bool xetTotNghiep() const override;
        int loai() const override;
};

#endif // SVIEN_H
