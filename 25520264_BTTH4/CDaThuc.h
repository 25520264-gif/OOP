#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>
#include <vector>


class CDaThuc
{
    private:
        std::vector<double> heso;

    public:
        //Constructor
        CDaThuc();
        CDaThuc(std::vector<double> hs);

        //Ham thanh phan
        friend std::istream& operator>> (std::istream& is, CDaThuc& a);
        friend std::ostream& operator<< (std::ostream& os, const CDaThuc& a);

        int getDegree() const;
        double evaluate(double x) const;

        //Phep toan
        CDaThuc operator + (const CDaThuc& a) const;
        CDaThuc operator - (const CDaThuc& a) const;
        CDaThuc operator * (const CDaThuc& a) const;
};
#endif // CDATHUC_H
