#include <iostream>
#include <Nvien.h>

typedef long long ll;

using namespace std;

int main()
{
    vector<Nvien*> dsNV;
    int n, loai;

    cout<< "Nhap so luong nhan vien: "; cin>> n;

    for(int i =0; i < n;i++)
    {
        cout<< "\nChon loai NV (1: San Xuat; 2: Van Phong): ";cin>> loai;

        Nvien* nv = (loai == 1) ? (Nvien*)new Nvien_SX() : (Nvien*)new Nvien_VP();
        cin>> *nv;
        dsNV.push_back(nv);
    }

    cout<< "\n--- DANH SACH NHAN VIEN ---"<< endl;
    ll tong = 0;
    for(auto nv : dsNV)
    {
        cout<< *nv;
        tong += nv->TinhLuong();
    }
    cout<< "\n=> TONG LUONG: "<< tong<< " VND "<< endl;

    //Tim nhan vien san xuat luong thap nhat
    Nvien_SX* minSX = nullptr;
    for(auto nv : dsNV)
    {
        Nvien_SX* sx = dynamic_cast<Nvien_SX*>(nv);
        if(sx && (!minSX || sx->TinhLuong()< minSX->TinhLuong())) minSX = sx;
    }
    if(minSX) cout<< "\nNV San xuat luong thap nhat: "<< minSX->getHoTen()<< endl;

    //Tim nhan vien van phong tuoi cao nhat
    Nvien_VP* maxVP = nullptr;
    for(auto nv : dsNV)
    {
        Nvien_VP* vp = dynamic_cast<Nvien_VP*>(nv);
        if(vp && (!maxVP || vp->TinhTuoi() < maxVP->TinhTuoi())) maxVP = vp;
    }
    if(maxVP) cout<< "NV Van phong tuoi cao nhat: "<< maxVP->getHoTen()<< endl;

    for(auto nv : dsNV) delete nv;

    return 0;
}


