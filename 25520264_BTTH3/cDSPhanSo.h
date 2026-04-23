#pragma once
#include "PhanSo.h"
#include <vector>

class ds_p {
private:
    vector<PhanSo> ds;

public:
    void Nhap();
    void Xuat();

    PhanSo Tong();
    PhanSo LonNhat();
    PhanSo NhoNhat();

    PhanSo TuNguyenToLonNhat();

    void TangDan();
    void GiamDan();

    bool LaNguyenTo(int n);
};
