#ifndef CLISTNHANVIENVP_H
#define CLISTNHANVIENVP_H

#include "cNhanVienVP.h"
#include <vector>
using namespace std;

class cListNhanVienVP
{
private:
    vector<cNhanVienVP> ds;

public:
    void Nhap();
    void Xuat();
    void LuongCaoNhat();
    double TongLuong();
    void TuoiCaoNhat();
    void SapXepTangDanLuong();
};

#endif
