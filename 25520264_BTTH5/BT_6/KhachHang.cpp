#include "KhachHang.h"

KhachHang::KhachHang() : tenKhachHang(""), soLuongHang(0), donGiaHang(0.0) {}
KhachHang::~KhachHang() {}

void KhachHang::docFile(std::ifstream &fileIn)
{
    fileIn >> std::ws; // Xóa khoảng trắng/dòng trống thừa nếu có
    std::getline(fileIn, tenKhachHang);
    fileIn >> soLuongHang >> donGiaHang;
}

std::string KhachHang::getTenKhachHang() const
{
    return tenKhachHang;
}

//Loai A
double KhachHangA::tinhSoTienPhaiTra()
{
    double thanhTien = soLuongHang * donGiaHang;
    double thueVAT = thanhTien * 0.10;
    return thanhTien + thueVAT;
}

//Loai B
void KhachHangB::docFile(std::ifstream &fileIn)
{
    KhachHang::docFile(fileIn);
    fileIn >> soNamThanThiet;
}

double KhachHangB::tinhSoTienPhaiTra()
{
    double phanTramKhuyenMai = std::max(soNamThanThiet * 0.05, 0.50);
    double thanhTien = (soLuongHang * donGiaHang) * (1.0 - phanTramKhuyenMai);
    double thueVAT = thanhTien * 0.10;
    return thanhTien + thueVAT;
}

// Loai C
double KhachHangC::tinhSoTienPhaiTra()
{
    double thanhTien = (soLuongHang * donGiaHang) * 0.50;
    double thueVAT = thanhTien * 0.10;
    return thanhTien + thueVAT;
}
