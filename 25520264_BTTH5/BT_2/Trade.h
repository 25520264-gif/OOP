#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <iostream>

typedef long long ll;

using namespace std;

class Trade
{
    protected:
        string maGiaoDich;
        string ngayGiaoDich;
        ll donGia;
        double dienTich;
    public:
        Trade();
        virtual ~Trade() = default;

        //Nhap/Xuat
        friend istream& operator>> (istream& is, Trade& a)
        {
            return a.Nhap(is);
        }
        virtual istream& Nhap(istream& is);

        friend ostream& operator<< (ostream& os, const Trade& a)
        {
            return a.Xuat(os);
        }
        virtual ostream& Xuat(ostream& os) const;

        virtual double tinhThanhtien() const = 0;

        string getngayGiaoDich() const { return ngayGiaoDich; }
};

//Giao dich dat
class Trade_e : public Trade
{
    private:
        string loaiDat;
    public:
        istream& Nhap(istream& is) override;
        ostream& Xuat(ostream& os) const override;
        double tinhThanhtien() const override;
};

//Giao dich nha pho
class Trade_h : public Trade
{
    private:
        string loaiNha;
        string diaChi;
    public:
        istream& Nhap(istream& is) override;
        ostream& Xuat(ostream& os) const override;
        double tinhThanhtien() const override;
};

//Giao dich can ho chung cu
class Trade_a : public Trade
{
    private:
        string maCan;
        int vitriTang;
    public:
        istream& Nhap(istream& is) override;
        ostream& Xuat(ostream& os) const override;
        double tinhThanhtien() const override;
};

#endif // TRADE_H
