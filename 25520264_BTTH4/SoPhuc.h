#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc
{
    private:
        double ithuc, iao;
    public:
        //Constructor
         SoPhuc();
         SoPhuc(double t = 0.0, double a = 0.0);

         //Input/Output
         friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
         friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);

         //Phep toan
         SoPhuc operator + (SoPhuc& a)const;
         SoPhuc operator - (SoPhuc& a)const;
         SoPhuc operator * (SoPhuc& a)const;
         SoPhuc operator / (SoPhuc& a)const;

         //So sanh
         bool operator == (SoPhuc& a);
         bool operator != (SoPhuc& a);

};

#endif // SOPHUC_H
