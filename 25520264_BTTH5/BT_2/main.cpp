#include <Trade.h>

#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector <Trade*> ds;
    int n1, n2, n3;

    cout<< "So luong giao dich dat: "; cin>> n1;
    for(int i =0; i < n1;i++)
    {
        Trade_e* g = new Trade_e();
        cin>> *g;
        ds.push_back(g);
    }

    cout<< "So luong giao dich nha pho: "; cin>> n2;
    for(int i =0; i < n2;i++)
    {
        Trade_h* g = new Trade_h();
        cin>> *g;
        ds.push_back(g);
    }

    cout<< "So luong giao dich can ho chung cu: "; cin>> n3;
    for(int i = 0;i < n3;i++)
    {
        Trade_a* g = new Trade_a();
        cin>> *g;
        ds.push_back(g);
    }

    //Tong so luong
    cout<< "\n===SO LUONG TUNG LOAI GIAO DICH===\n";
    cout<< "Giao dich dat: "<< n1<< "\nGiao dich nha pho: "<< n2<< "\nGiao dich can ho chung cu: "<< n3<< endl;

    //Trung binh thanh tien GD can ho chung cu
    double tong = 0;
    for(auto g : ds)
    {
        if(dynamic_cast<Trade_a*>(g)) tong += g->tinhThanhtien();
    }
    if(n3 > 0) cout<< "Trung binh thanh tien can ho: "<< (long long)(tong/n3)<< endl;

    //Nha pho gia cao nhat
    Trade_h* maxNha = nullptr;
    for(auto g : ds)
    {
        Trade_h* temp = dynamic_cast<Trade_h*>(g);
        if(temp && (!maxNha || temp->tinhThanhtien() > maxNha->tinhThanhtien())) maxNha = temp;
    }
    if(maxNha)
    {
        cout<< "\nGiao dich nha pho cao nhat: "<< *maxNha;
    }

    //Xuat giao dich thang 12/2024
    cout<< "\n--- Giao dich thang 12/2024 ---\n";
    for(auto g : ds)
    {
        if(g->getngayGiaoDich().find("/12/2024") != string::npos) cout<< *g;
    }

    for(auto g : ds) delete g;

    return 0;
}
