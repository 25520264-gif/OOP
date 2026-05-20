#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;

public:
    virtual ~NhanVien();

    friend istream& operator>>(istream& is, NhanVien& a)
    {
        return a.Nhap(is);
    }
    virtual istream& Nhap(istream& is);

    friend ostream& operator<< (ostream& os, const NhanVien& a)
    {
        return a.Xuat(os);
    }
    virtual ostream& Xuat(ostream& os) const;


    virtual double tinhLuong() const = 0;
    virtual int loaiNhanVien() const = 0;

    string getHoTen() const;
};

//Lap trinh vien
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    istream& Nhap(istream& is) override;
    ostream& Xuat(ostream& os) const override;

    double tinhLuong() const override;
    int loaiNhanVien() const override;
};

//Kiem chung vien
class KiemChungVien : public NhanVien {
private:
    int soLoi;

public:
    istream& Nhap(istream& is) override;
    ostream& Xuat(ostream& os) const override;

    double tinhLuong() const override;
    int loaiNhanVien() const override;
};



#endif // NHANVIEN_H
