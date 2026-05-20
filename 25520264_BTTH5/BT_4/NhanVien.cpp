#include "NhanVien.h"
#include <iomanip>

NhanVien::~NhanVien() {}

istream& NhanVien::Nhap(istream& is)
{
    cout << "Nhap ma nhan vien: "; getline(is>> ws, maNV);
    cout << "Nhap ho ten: "; getline(is>> ws, hoTen);
    cout << "Nhap tuoi: "; cin >> tuoi;
    cout << "Nhap so dien thoai: "; getline(is>> ws, sdt);
    cout << "Nhap email: "; getline(is>> ws, email);
    cout << "Nhap luong co ban: "; cin >> luongCoBan;

    return is;
}

ostream& NhanVien::Xuat(ostream& os) const
{
    os<< "Ma nhan vien: "<< left<< setw(20)<< maNV
      << " | Ho ten: "<< setw(12)<< hoTen
      << " | Tuoi: "<< tuoi<< " | So dien thoai: "
      << sdt<< " | Email: "<< email;

      return os;
}

string NhanVien::getHoTen() const
{
    return hoTen;
}

istream& LapTrinhVien::Nhap(istream& is)
{
    NhanVien::Nhap(is);
    cout << "Nhap so gio them: "; is >> soGioOvertime;

    return is;
}

ostream& LapTrinhVien::Xuat(ostream& os) const
{
    os<< "\nLap trinh vien\n";
    NhanVien::Xuat(os);
    os<< " | So gio lam them: "<< soGioOvertime
      << " | Luong: "<< fixed<< setprecision(0)<< tinhLuong()<< endl;

      return os;
}

double LapTrinhVien::tinhLuong() const
{
    return luongCoBan + soGioOvertime * 200000.0;
}

int LapTrinhVien::loaiNhanVien() const
{
    return 1;
}

istream& KiemChungVien::Nhap(istream& is)
{
    NhanVien::Nhap(is);
    cout << "Nhap so loi phat hien: "; is >> soLoi;

    return is;
}

ostream& KiemChungVien::Xuat(ostream& os) const
{
    os<< "\nKiem chug vien\n";
    NhanVien::Xuat(os);
    os<< " | So loi phat hien: "<< soLoi
      << " | Luong: "<< fixed<< setprecision(0)<< tinhLuong()<< endl;

    return os;
}

double KiemChungVien::tinhLuong() const
{
    return luongCoBan + soLoi * 50000.0;
}

int KiemChungVien::loaiNhanVien() const
{
    return 2;
}

