#ifndef CLISTNHANVIENSX_H
#define CLISTNHANVIENSX_H

#include "cNhanVienSX.h"
#include <vector>
using namespace std;

class cListNhanVienSX
{
private:
    vector<cNhanVienSX> ds;

public:
    void Nhap();
    void Xuat();
    void LuongThapNhat();
    double TongLuong();
    void TuoiCaoNhat();
    void SapXepTangDanLuong();
};

#endif
