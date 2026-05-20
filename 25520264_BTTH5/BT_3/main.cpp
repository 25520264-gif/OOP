#include <Svien.h>

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <Svien*> ds;
    int n;

    //Nhap vao danh sach cac sinh vien
    cout<< "Nhap so luong sinh vien: "; cin>> n;

    for(int i =0;i < n;i++)
    {
        cout<< "\n--- Nhap thong tin sinh vien thu "<< i + 1<< " ---\n";
        cout<< "Chon he dao tao (1: Cao dang, 2: Dai hoc): ";
        int chon; cin>> chon;

        Svien* sv = nullptr;
        if(chon == 1) sv = new Svien_CD;
        else if(chon == 2) sv = new Svien_DH;
        else
        {
            cout<< "Lua chon khong hop le! Mac dinh cho Cao dang.\n";
            sv = new Svien_CD;
        }

        cin>> *sv;
        ds.push_back(sv);
    }

    //b. Xuat danh sach cac sinh vien
    cout<< "\n=========================\n";
    cout<< "b. DANH SACH TAT CA SINH VIEN\n";
    for(const auto& sv : ds)
    {
        cout<< *sv;
    }

    //c. Xuat danh sach sih vien tot nghiep
    cout<< "\n=========================\n";
    cout<< "c. DANH SACH SINH VIEN TOT NGHIEP:\n";
    for(const auto& sv : ds)
    {
        if(sv->xetTotNghiep())
            cout<< *sv;
    }

    //e. Sinh vien dai hoc co diem trung binh cao nhat
    cout<< "\n=========================\n";
    Svien* max_svDH = nullptr;
    for(const auto& sv : ds)
    {
        if(sv->loai() == 2)
        {
            if(max_svDH == nullptr || sv->getDTB() > max_svDH->getDTB())
                max_svDH = sv;
        }
    }
    cout<< "e. SINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT:\n";
    if(max_svDH != nullptr)
        cout<< *max_svDH;
    else
        cout<< "KHONG CO SINH VIEN DAI HOC TRONG DANH SACH.\n";

    //f. Sinh vien cao dang co diem cao nhat
    cout<< "\n=========================\n";
    Svien* max_svCD = nullptr;
    for(const auto& sv : ds)
    {
        if(sv->loai() == 1)
        {
            if(max_svCD == nullptr || sv->getDTB() > max_svCD->getDTB())
                max_svCD = sv;
        }
    }
    cout<< "f. SINH VIEN CAO DANG CO DIEM TRUNG BINH CAO NHAT:\n";
    if(max_svCD != nullptr)
        cout<< *max_svCD;
    else
        cout<< "KHONG CO SINH VIEN CAO DANG TRONG DANH SACH.\n";

    //g.Co bao nhieu sinh vien moi loai khong du dieu kien tot nghiep
    int countCD_0TN = 0;
    int countDH_0TN = 0;

    for(const auto& sv : ds)
    {
        if(!sv->xetTotNghiep())
        {
            if(sv->loai() == 1) countCD_0TN++;
            else if(sv->loai() == 2) countDH_0TN++;
        }
    }
    cout<< "\n=========================\n";
    cout<< "e. THONG KE SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP:\n";
    cout<< "- So sinh vien cao dang chua tot nghiep: "<< countCD_0TN<< endl;
    cout<< "- So sinh vien dai hoc chua tot nghiep: "<< countDH_0TN<< endl;

    //Giai phong bo nho
    for(auto& sv : ds)
        delete sv;
    ds.clear();

    return 0;
}
