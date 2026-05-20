#include "Svien.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

istream& Svien::Nhap(istream& is)
{
    is.ignore();

    cout<< "Nhap ma so sinh vien (8 chu so): ";
    while(true)
    {
        getline(is>> ws, MSSV);
        if(MSSV.length() == 8) break;
        cerr<< "Loi! Vui long nhap dung do dai: ";
    }

    cout<< "Nhap ho ten: "; getline(is>> ws, HoTen);
    cout<< "Nhap dia chi: "; getline(is>> ws, diaChi);

    cout<< "Nhap tong so tin chi: "; is>> tinChi;
    cout<< "Nhap diem trung binh: "; is>> DTB;

    return is;
}

ostream& Svien::Xuat(ostream& os) const
{
    cout<< "Ho va ten: "<< left<< setw(20)<< HoTen
        << " | MSSV: "<< setw(12)<< MSSV
        << " | Dia chi: "<< diaChi<< " | Tin chi: "
        << tinChi<< " | Diem trung binh: "<< DTB;

    return os;
}

double Svien::getDTB() const
{
    return DTB;
}

string Svien::getHoTen() const
{
    return HoTen;
}

//Sinh vien cao dang
istream& Svien_CD::Nhap(istream& is)
{
    Svien::Nhap(is);
    cout<< "Nhap diem thi tot nghiep: "; is>> diemTN;

    return is;
}

ostream& Svien_CD::Xuat(ostream& os) const
{
    Svien::Xuat(os);
    os<< " | Diem thi tot nghiep: "<< diemTN<< endl
      << " -> "  << (xetTotNghiep() ? "DU DIEU KIEN TOT NGHIEP" : "KHONG DU DIEU KIEN TOT NGHIEP")<< endl;

    return os;
}

bool Svien_CD::xetTotNghiep() const
{
    return (tinChi >= 120 && DTB >= 5 && diemTN >= 5);
}

int Svien_CD::loai() const
{
    return 1;
}

//Sinh vien dai hoc
istream& Svien_DH::Nhap(istream& is)
{
    Svien::Nhap(is);
    is.ignore();
    cout<< "Nhap ten luan van: "; getline(is>> ws, tenLuanVan);
    cout<< "Nhap diem luan van: "; is>> diemLuanVan;

    return is;
}

ostream& Svien_DH::Xuat(ostream& os) const
{
    Svien::Xuat(os);
    os<< " | Luan van: "<< tenLuanVan<< " | Diem luan van: "<< diemLuanVan<< endl
      << "-> " << (xetTotNghiep() ? "DU DIEU KIEN TOT NGHIEP" : "KHONG DU DIEU KIEN TOT NGHIEP")<< endl;

    return os;
}

bool Svien_DH::xetTotNghiep() const
{
    return (tinChi >= 170 && DTB >= 5 && diemLuanVan >= 5);
}

int Svien_DH::loai() const
{
    return 2;
}
