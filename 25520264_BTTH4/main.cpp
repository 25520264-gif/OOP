#include <iostream>

#include <SoPhuc.h>
#include <PhanSo.h>
#include <CTime.h>
#include <CDate.h>
#include <CDaThuc.h>
#include <CVector.h>
#include <CMatrix.h>

using namespace std;

void SP();
void PS();
void CT();
void LaiSuat();
void CDT();
void CV();
void CM();

int main()
{
    SP();
    PS();
    CT();
    LaiSuat();
    CDT();
    CV();
    CM();

    return 0;
}

void SP()
{
    SoPhuc x,y;

    cin>> x>> y;
    cout<< x<< " "<< y<< endl;
    cout<< x + y<< endl;
    cout<< x - y<< endl;
    cout<< x * y<< endl;
    cout<< x / y<< endl;
    if(x == y) cout<< "YES";
    else cout<< "NO";
}

void PS()
{
    PhanSo x, y;

    cin>> x>> y;
    cout<< x<< endl<< y<< endl;

    cout<< x + y<< endl;
    cout<< x - y<< endl;
    cout<< x * y<< endl;
    cout<< x / y<< endl;

    if(x == y)cout<< "BANG";
    else if(x > y)cout<< "x lon hon y";
    else if(x < y)cout<< "x be hon y";
}

void CT()
{
    CTime x,y,a,b,c,d;
    cin>> x>>y;
    cout<< "Gio x/y: \n";
    cout<< x<< y;

    a = x++;
    cout<< "\nGio x sau khi (x++):\n"<< x;
    b = ++x;

    c = y--;
    cout<< "\nGio y sau khi (y--):\n"<< y;
    d = --y;

    cout<< "\nGio a/b/c/d: \n";
    cout<< "Gio a: "<< a<< endl;
    cout<< "Gio b: "<< b<< endl;
    cout<< "Gio c: "<< c<< endl;
    cout<< "Gio d: "<< d<< endl;

    int i,j;
    cout<< "\nNhap so giay cong: ";cin>> i;
    cout<< "\nNhap so giay tru: "; cin>> j;
    cout<< "Thoi gian sau khi cong "<< i<< " giay cho a la: "<< a + i<< endl;
    cout<< "Thoi gian sau khi tru "<< j<< " giay cho b la: "<< b - j;
}

void LaiSuat()
{
    CDate ngayGui, ngayRut;
    double tienGoc, laiSuatNam;

    cout << "--- CHUONG TRINH TINH LAI SUAT NGAN HANG ---\n" << endl;
    cout << "Nhap ngay gui (dd mm yyyy): \n";
    cin >> ngayGui;
    cout << "Nhap ngay rut (dd mm yyyy): \n";
    cin >> ngayRut;
    cout << "Nhap so tien goc (VND): ";
    cin >> tienGoc;
    cout << "Nhap lai suat nam (%): ";
    cin >> laiSuatNam;

    // Tinh so ngay gui bang cach su dung toan tu tru hai CDate
    long soNgayGui = ngayRut - ngayGui;

    if (soNgayGui < 0) {
        cout << "Loi: Ngay rut phai sau ngay gui!" << endl;
    } else {
        double laiSuatNgay = (laiSuatNam / 100) / 365;
        double tienLai = tienGoc * laiSuatNgay * soNgayGui;

        cout << "\nKet qua:" << endl;
        cout << "So ngay gui: " << soNgayGui << " ngay." << endl;
        cout << "Tien lai nhan duoc: " << (long long)tienLai << " VND" << endl;
        cout << "Tong so tien nhan duoc: " << (long long)(tienGoc + tienLai) << " VND" << endl;
    }
}

void CDT()
{
    CDaThuc p1, p2;

    cout<< "Nhap da thuc 1: \n";cin>> p1;
    cout<< "Nhap da thuc 2: \n";cin>> p2;

    cout<< "P1: ";cout<< p1<< endl;
    cout<< "P2: ";cout<< p2<< endl;

    //Phep toan
    CDaThuc tong = p1 + p2;
    cout<< "Tong 2 da thuc: "<< tong<< endl;
    CDaThuc hieu = p1 - p2;
    cout<< "Hieu 2 da thuc: "<< hieu<< endl;
    CDaThuc tich = p1 * p2;
    cout<< "Tich 2 da thuc: "<< tich<< endl;

    double x;
    cout<< "\nNhap x de tinh gia tri P1(x): ";cin>> x;
    cout<< "P1("<< x<< ") = "<< p1.evaluate(x)<< endl;
}

void CV()
{
    CVector v1, v2;

    cout << "Nhap vector thu nhat:\n";
    cin >> v1;
    cout << "Nhap vector thu hai:\n";
    cin >> v2;

    cout << "\nVector 1: " << v1;
    cout << "\nVector 2: " << v2;

    CVector tong = v1 + v2;
    CVector hieu = v1 - v2;
    double tich = v1 * v2;

    cout << "\n\n--- Ket qua phep toan ---";
    cout << "\nTong v1 + v2 = " << tong;
    cout << "\nHieu v1 - v2 = " << hieu;
    cout << "\nTich vo huong v1 * v2 = " << tich << endl;
}

void CM()
{
    CMatrix m1, m2;
    cout << "--- Nhap Ma tran 1 ---\n";
    cin >> m1;
    cout << "--- Nhap Ma tran 2 ---\n";
    cin >> m2;

    cout << "\nMa tran 1:\n" << m1;
    cout << "\nMa tran 2:\n" << m2;

    CMatrix tichMaTran = m1 * m2;
    cout << "\nTich hai ma tran:\n" << tichMaTran;

    // Test nhan Ma tran voi Vector
    CVector v1;
    cout << "\n--- Nhap Vector de nhan voi Ma tran 1 ---\n";
    cin >> v1;
    CVector ketQua = m1 * v1;
    cout << "Ket qua Matrix * Vector: " << ketQua;
}
