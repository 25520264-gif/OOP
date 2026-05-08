#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include "CVector.h"

using namespace std;

class CMatrix {
private:
    int rows, cols;
    double** data;

public:
    //Constructor
    CMatrix();
    CMatrix(int r, int c);
    CMatrix(const CMatrix& m);
    ~CMatrix();

    //Input/Output
    friend istream& operator>>(istream& is, CMatrix& m);
    friend ostream& operator<<(ostream& os, const CMatrix& m);

    //Gan
    CMatrix& operator=(const CMatrix& m);

    // Phep toan
    CMatrix operator*(const CMatrix& m) const;
    CVector operator*(const CVector& v) const;

};

#endif // CMATRIX_H
