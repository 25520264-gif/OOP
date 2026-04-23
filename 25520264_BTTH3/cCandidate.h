#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include <iostream>
using namespace std;

class cCandidate
{
private:
    string ma, ten;
    int ngay, thang, nam;
    float toan, van, anh;

public:
    void Nhap();
    void Xuat();
    float TongDiem();
};

#endif
