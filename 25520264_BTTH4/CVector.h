#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector
{
    private:
        int n;
        double* data;

    public:
        CVector();
        CVector(int numSize);
        CVector(const CVector& v);
        ~CVector();

        //Input/Output
        friend istream& operator>> (istream& is, CVector& a);
        friend ostream& operator<< (ostream& os, const CVector& a);

        //toan tu gan
        CVector& operator = (const CVector& v);

        //Phep toan
        CVector operator + (const CVector& v) const;
        CVector operator - (const CVector& v) const;
        double operator * (const CVector& v) const;

        friend class CMatrix;
};

#endif // CVECTOR_H
