#include "CMatrix.h"
using namespace std;

CMatrix::CMatrix() : rows(0), cols(0), data(nullptr) {}

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols]();
    }
}

CMatrix::CMatrix(const CMatrix& m) : rows(m.rows), cols(m.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) data[i][j] = m.data[i][j];
    }
}

CMatrix::~CMatrix() {
    for (int i = 0; i < rows; i++) delete[] data[i];
    delete[] data;
}

istream& operator>>(istream& is, CMatrix& m) {
    cout << "Nhap so hang va so cot: ";
    is >> m.rows >> m.cols;
    m.data = new double*[m.rows];
    for (int i = 0; i < m.rows; i++) {
        m.data[i] = new double[m.cols];
        for (int j = 0; j < m.cols; j++) {
            cout << "Mat[" << i << "][" << j << "]: ";
            is >> m.data[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) os << m.data[i][j] << "\t";
        os << "\n";
    }
    return os;
}

CMatrix& CMatrix::operator=(const CMatrix& m) {
    if (this != &m) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;

        rows = m.rows; cols = m.cols;
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols]();
            for (int j = 0; j < cols; j++) data[i][j] = m.data[i][j];
        }
    }
    return *this;
}

CMatrix CMatrix::operator*(const CMatrix& m) const {
    if (this->cols != m.rows) return CMatrix();
    CMatrix res(this->rows, m.cols);
    for (int i = 0; i < res.rows; i++) {
        for (int j = 0; j < res.cols; j++) {
            for (int k = 0; k < this->cols; k++)
                res.data[i][j] += this->data[i][k] * m.data[k][j];
        }
    }
    return res;
}

CVector CMatrix::operator*(const CVector& v) const {
    if (this->cols != v.n) {
        cout << "\nLoi: Kich thuoc Matrix (" << this->cols << " cot) khong khop voi Vector (" << v.n << " chieu)!";
        return CVector();
    }

    CVector res(this->rows);

    for (int i = 0; i < this->rows; i++) {
        // Lưu ý: res.data[i] đã được khởi tạo = 0 trong constructor CVector
        for (int j = 0; j < this->cols; j++) {
            res.data[i] += this->data[i][j] * v.data[j];
        }
    }

    return res;
}
