#ifndef CLISTCANDIDATE_H
#define CLISTCANDIDATE_H

#include "cCandidate.h"
#include <vector>
using namespace std;

class cListCandidate
{
private:
    vector<cCandidate> ds;

public:
    void Nhap();
    void XuatLonHon15();
    void ThiSinhCaoDiemNhat();
    void SapXepGiamDan();
    void XuatDanhSach();
};

#endif
