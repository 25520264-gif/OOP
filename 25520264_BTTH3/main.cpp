#include "DIEM.h"
#include "cTamGiac.h"
#include "cDaGiac.h"
#include "cDSPhanSo.h"
#include "cArray.h"
#include "cDaThuc.h"
#include "cListCandidate.h"
#include "cListNhanVienVP.h"
#include "cListNhanVienSX.h"
#include <iostream>

using namespace std;

//void cTamGiac();
//void cDaGiac();
//void cDSPHanSo();
//void cArray();
//void cDaThuc();
//void cLC();
//void cVP();
void cSX();

int main()
{
    //cTamGiac();
    //cDaGiac();
    //cDSPHanSo();
    //cArray();
    //cDaThuc();
    //cLC();
    //cVP();
    cSX();

    return 0;
}

/*void cTamGiac()
{
    ctg a;

    cout<< "Nhap toa do tam giac 1: \n";
    a.Nhap();

    cout<< "Toa do tam giac 1: \n";
    a.Xuat();

    cout<< a.PhanLoai()<< endl;

    //Tính toán
    cout<< "Chu vi: "<< a.ChuVi()<< endl;
    cout<< "Dien tich: "<< a.DienTich()<< endl;

    //Tịnh Tiến
    double dx,dy;

    cout<< "Tinh tien truc x: ";
    cin>> dx;
    cout<< "Tinh tien truc y: ";
    cin>> dy;

    a.TinhTien(dx,dy);
    cout<< "Toa do tam giac 1 sau tinh tien: "<< endl;
    a.Xuat();
    cout<< a.PhanLoai()<< endl;

    //Quay
    double goc;
    cout<< "Nhap goc can quay: \n";
    cin>> goc;
    a.Quay(goc);

    cout<< "Toa do tam giac 1 sau khi quay: \n";
    a.Xuat();

    //Phóng to/thu nhỏ
    ctg b;
    cout<< "Nhap toa do tam giac 2: \n";
    b.Nhap();

    double x,y;

    cout<< "Nhap phong to tam giac 2 x lan: \n";
    cin>> x;
    b.PhongTo(x);
    cout<< "Toa do sau khi phong to "<< x<<" lan\n";
    b.Xuat();

    cout<< "Nhap thu nho tam giac y 2 lan: \n";
    cin>> y;
    b.ThuNho(y);
    cout<< "Toa do sau khi thu nho "<< y<<" lan\n";
    b.Xuat();
}*/

/*void cDaGiac()
{
    cdg a;

    cout << "Nhap da giac: \n";
    a.Nhap();

    cout << "Xuat da giac: \n";
    a.Xuat();

    cout << "\nChu vi: " << a.TinhChuVi();
    cout << "\nDien tich: " << a.TinhDienTich();

    cout << "\nTinh tien (1,2) \n";
    a.TinhTien(1, 2);
    a.Xuat();

    cout << "\nPhong to 2 lan \n";
    a.PhongTo(2);
    a.Xuat();

    cout << "\nThu nho 2 lan \n";
    a.ThuNho(2);
    a.Xuat();

    cout << "\nQuay 90 do \n";
    a.Quay(3.1415926535 / 2); // 90 độ
    a.Xuat();
}

void cDSPHanSo()
{
    ds_p ds;

    ds.Nhap();

    cout << "\nDanh sach:\n";
    ds.Xuat();

    cout << "\nTong: ";
    ds.Tong().Xuat();

    cout << "\nLon nhat: ";
    ds.LonNhat().Xuat();

    cout << "\nNho nhat: ";
    ds.NhoNhat().Xuat();

    cout << "\nTu la so nguyen to lon nhat: ";
    ds.TuNguyenToLonNhat().Xuat();

    cout << "\nSap xep tang:\n";
    ds.TangDan();
    ds.Xuat();

    cout << "\nSap xep giam:\n";
    ds.GiamDan();
    ds.Xuat();

}

void cArray()
{
    cArr arr;

    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    arr.TaoNgauNhien(n);

    cout << "Mang ban dau:\n";
    arr.Xuat();

    int x;
    cout << "Nhap x: ";
    cin >> x;

    cout << "So lan xuat hien cua " << x << ": "
         << arr.DemX(x) << endl;

    cout << "Mang co tang dan khong? ";
    cout << (arr.KiemTraTang() ? "Co\n" : "Khong\n");

    int le = arr.TimLeNhoNhat();
    if (le == -1)
        cout << "Khong co so le\n";
    else
        cout << "So le nho nhat: " << le << endl;

    int nt = arr.TimNTLonNhat();
    if (nt == -1)
        cout << "Khong co so nguyen to\n";
    else
        cout << "So NT lon nhat: " << nt << endl;

    arr.SapXepTang();
    cout << "Mang sau khi sap xep tang:\n";
    arr.Xuat();

    arr.SapXepGiam();
    cout << "Mang sau khi sap xep giam:\n";
    arr.Xuat();

}

void cDaThuc()
{
    cdt A, B, C, D;

    cout << "Nhap da thuc A:\n";
    A.Nhap();

    cout << "Nhap da thuc B:\n";
    B.Nhap();

    cout << "\nDa thuc A: ";
    A.Xuat();

    cout << "Da thuc B: ";
    B.Xuat();

    double x;
    cout << "\nNhap x: ";
    cin >> x;

    cout << "Gia tri A tai x = " << x << ": " << A.GiaTri(x) << endl;

    C = A.Cong(B);
    cout << "\nA + B = ";
    C.Xuat();

    D = A.Tru(B);
    cout << "A - B = ";
    D.Xuat();
}

void cLC()
{
    cListCandidate ds;

    ds.Nhap();

    ds.XuatLonHon15();

    ds.ThiSinhCaoDiemNhat();

    ds.SapXepGiamDan();

    cout << "\nSau khi sap xep giam dan:\n";
    ds.XuatDanhSach();

}

void cVP()
{
    cListNhanVienVP ds;

    ds.Nhap();

    ds.Xuat();

    ds.LuongCaoNhat();

    cout << "\nTong luong cong ty phai tra: " << ds.TongLuong() << endl;

    ds.TuoiCaoNhat();

    ds.SapXepTangDanLuong();

    cout << "\nSau khi sap xep tang dan theo luong:\n";
    ds.Xuat();
}*/

void cSX()
{
    cListNhanVienSX ds;

    ds.Nhap();

    ds.Xuat();

    ds.LuongThapNhat();

    cout << "\nTong luong cong ty phai tra: " << ds.TongLuong() << endl;

    ds.TuoiCaoNhat();

    ds.SapXepTangDanLuong();

    cout << "\nSau khi sap xep tang dan theo luong:\n";
    ds.Xuat();

}
