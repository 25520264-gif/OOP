#include "cCandidate.h"

void cCandidate::Nhap()
{
    cout << "Nhap ma: ";
    cin >> ma;
    cin.ignore();

    cout << "Nhap ten: ";
    getline(cin, ten);

    cout << "Nhap ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;

    cout << "Nhap diem Toan Van Anh: ";
    cin >> toan >> van >> anh;
}

void cCandidate::Xuat()
{
    cout << "Ma: " << ma << endl;
    cout << "Ten: " << ten << endl;
    cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
    cout << "Diem: Toan=" << toan
         << " Van=" << van
         << " Anh=" << anh << endl;
    cout << "Tong diem: " << TongDiem() << endl;
}

float cCandidate::TongDiem()
{
    return toan + van + anh;
}
