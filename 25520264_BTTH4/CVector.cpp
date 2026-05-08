#include "CVector.h"

CVector::CVector() :
    n(0), data(nullptr) {}

CVector::CVector(int numSize)
{
    n = numSize;
    data = new double[n];
    for(int i = 0;i < n;i++) data[i] = 0;
}

CVector::CVector(const CVector& v)
{
    n = v.n;
    data = new double[n];
    for(int i = 0; i < n; i++) data[i] = v.data[i];
}

CVector::~CVector()
{
    delete[] data;
}

istream& operator>> (istream& is, CVector& a)
{
    cout<< "Nhap so chieu n: ";
    is>> a.n;
    delete[] a.data;
    a.data = new double[a.n];
    for(int i = 0; i < a.n;i++)
    {
        cout<< "Thanh phan ["<< i<< "]: ";
        is>> a.data[i];
    }

    return is;
}

ostream& operator<< (ostream& os, const CVector& a)
{
    os<< "(";
    for(int i =0; i < a.n;i++)
    {
        os<< a.data[i]<< (i == a.n - 1 ?"":", ");
    }
    os<< ")";

    return os;
}

CVector& CVector::operator=(const CVector& v)
{
    if(this != &v)
    {
        delete[] data;
        n = v.n;
        data = new double[n];
        for(int i =0; i < n;i++) data[i] = v.data[i];
    }
    return *this;
}

CVector  CVector::operator+(const CVector& v) const
{
    if(n != v.n) return CVector();
    CVector res(n);
    for(int i = 0;i < n;i++) res.data[i] = data[i] + v.data[i];
    return res;
}

CVector  CVector::operator-(const CVector& v) const
{
    if(n != v.n) return CVector();
    CVector res(n);
    for(int i = 0;i < n;i++) res.data[i] = data[i] - v.data[i];
    return res;
}

double CVector::operator*(const CVector& v) const
{
    double dotProduct = 0;
    if(n == v.n)
    {
        for(int i =0; i< n; i++) dotProduct += data[i] * v.data[i];
    }

    return dotProduct;
}
