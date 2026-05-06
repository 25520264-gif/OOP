#include "SoPhuc.h"
#include <cmath>


//Input/Output
std::istream& operator>>(std::istream& is, SoPhuc& sp)
{
    is>> sp;
    return is;
}

std::ostream& operator<<(std::ostream& os, const SoPhuc& sp)
{
    if(sp.iao >= 0)
        os<< sp.ithuc<< " + "<< sp.iao;
    else
        os<< sp.ithuc<< " - "<< -sp.iao;
}

//Phep toan
SoPhuc operator + (SoPhuc& a)const{
    SoPhuc tong;

    tong.ithuc = this->ithuc + a.ithuc;
    tong.iao = this->iao + a.iao;

    return tong;
}

SoPhuc operator - (SoPhuc& a)const{
    SoPhuc hieu;

    hieu.ithuc = this->ithuc - a.ithuc;
    hieu.iao = this->iao - a.iao;

    return hieu;
}

SoPhuc operator * (SoPhuc& a)const{
    SoPhuc tich;

    tich.ithuc = ithuc * a.ithuc - iao * a.iao;
    tich.iao = ithuc * a.iao + iao * a.ithuc;

    return tich;
}

SoPhuc operator / (SoPhuc& a)const{
    SoPhuc thuong;

    double mau = pow(a.ithuc) + pow(a.iao);
    if(mau == 0)
        {
            std::cerr<< "Loi chia cho so phuc bang 0!"<< std::end;
            return SoPhuc(0,0)
        }


    thuong.ithuc = (ithuc * a.ithuc + iao * a.iao)/(pow(a.ithuc) + pow(a.iao));
    thuong.iao = (iao * a.ithuc - ithuc * a.iao)/(pow(a.ithuc) + pow(a.iao));

    return thuong;
}

//So sanh

bool SoPhuc::operator == (SoPhuc& a)
{
    return (ithuc == a.ithuc) && (iao == a.iao);
}

bool SoPhuc::operator!=(SoPhuc& a)
{
    return (ithuc != a.ithuc) || (iao != a.iao);
}
