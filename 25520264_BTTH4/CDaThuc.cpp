#include "CDaThuc.h"
#include <cmath>
#include <algorithm>
#include <iostream>

CDaThuc::CDaThuc() {}

CDaThuc::CDaThuc(std::vector<double> hs) : heso(hs)
{
    while (heso.size() > 1 && heso.back() == 0)
    {
        heso.pop_back();
    }
}

std::istream& operator>> (std::istream& is, CDaThuc& a)
{
    int d;
    std::cout<< "Nhap bac cua da thuc: ";
    std::cin>> d;
    a.heso.resize(d + 1);
    for(int i =0; i <= d; ++i)
    {
        std::cout<< "He so cua bac "<< i<< " : ";
        std::cin>> a.heso[i];
    }
    return is;
}

int CDaThuc::getDegree() const
{
    return heso.empty() ? 0 : (int)heso.size() - 1;
}

std::ostream& operator<< (std::ostream& os, const CDaThuc& a)
{
    if(a.heso.empty())
    {
        os<< "0";
        return os;
    }
    for(int i = a.getDegree(); i >= 0; --i)
    {
        if(a.heso[i] == 0)continue;

        if(i < a.getDegree() && a.heso[i] > 0) std::cout<< " + ";
        if(a.heso[i] < 0)std::cout<< "-";

        double hs_abs = std::abs(a.heso[i]);
        if(hs_abs != 1 || i == 0) std::cout<< hs_abs;

        if(i > 0) os<< "x";
        if(i > 1) os<< "^"<< i;
    }

    return os;
}

double CDaThuc::evaluate(double x) const
{
    double result = 0;
    for(int i = getDegree(); i >= 0; --i)
    {
        result = result * x + heso[i];
    }

    return result;
}

CDaThuc CDaThuc::operator + (const CDaThuc& a) const
{
    int maxDeg = std::max(getDegree(), a.getDegree());
    std::vector<double> reshs(maxDeg + 1, 0);
    for(int i = 0;i <= maxDeg; ++i)
    {
        if(i <= a.getDegree()) reshs[i] += heso[i];
        if(i <= getDegree()) reshs[i] += a.heso[i];
    }

    return CDaThuc(reshs);
}

CDaThuc CDaThuc::operator - (const CDaThuc& a) const
{
    int maxDeg = std::max(getDegree(), a.getDegree());
    std::vector<double> reshs(maxDeg + 1, 0);
    for(int i = 0;i <= maxDeg; ++i)
    {
        if(i <= a.getDegree()) reshs[i] -= a.heso[i];
        if(i <= getDegree()) reshs[i] += heso[i];
    }

    return CDaThuc(reshs);
}

CDaThuc CDaThuc::operator * (const CDaThuc& a) const
{
    int newDeg = getDegree() + a.getDegree();
    std::vector<double> reshs(newDeg + 1, 0);
    for(int i = 0;i <= getDegree(); ++i)
    {
        for(int j =0; j<= a.getDegree(); ++j)
        {
            reshs[i+j] += heso[i] * a.heso[j];
        }
    }

    return CDaThuc(reshs);
}



