#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class KhachHang
{
protected:
    std::string tenKhachHang;
    int soLuongHang;
    double donGiaHang;

public:
    KhachHang();
    virtual ~KhachHang();

    virtual void docFile(std::ifstream &fileIn);
    virtual double tinhSoTienPhaiTra() = 0;

    std::string getTenKhachHang() const;
};

//Loai A
class KhachHangA : public KhachHang
{
public:
    double tinhSoTienPhaiTra() override;
};

//Loai B
class KhachHangB : public KhachHang
{
private:
    int soNamThanThiet;

public:
    void docFile(std::ifstream &fileIn) override;
    double tinhSoTienPhaiTra() override;
};

// Loai C
class KhachHangC : public KhachHang
{
public:
    double tinhSoTienPhaiTra() override;
};

#endif // KHACHHANG_H
