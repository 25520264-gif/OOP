#include <iostream>
#include <string.h>
using namespace std;

#define mx 400

int main()
{
    char s[mx];
    cout<< "Nhap dung dinh dang-dd/mm/yyyy \n";
    cout<< "Nhap: ";    // Nhap: 31/12/2009
    cin.getline(s, mx);

    // Chuyen char --> int
    int d = (s[0]-'0')*10 + (s[1]-'0');    // d = 31
    int m = (s[3]-'0')*10 + (s[4]-'0');    // m = 12

    int i = strlen(s) - 1;
    int y = 0;
    int base = 1;

    // Tim nam
    while(s[i] != '/')    // y = 2009
    {
        y += (s[i]-'0') * base;
        base *= 10;
        i--;
    }

    // Cong so trong nam
    i =6;
    int n =0;
    while(s[i] != '\0')    // n = 2 + 0 + 0 +9 = 11
    {
        n += s[i] - '0';
        i++;
    }

    // Tim so ngay
    int songay;
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: songay =31;break;    // songay = 31
        case 4:
        case 6:
        case 9:
        case 11: songay =30;break;
        default:
            {
                // La nam nhuan && thang 2 --> so ngay 
                if(n % 4 == 0)songay =29;
                else songay = 28;
            }
    }
    d++;    // d = 32
    if(d > songay)    // d = 32 > songay = 31
    {
        d = 1;          // d = 1
        m++;            // m = 13
        if(m > 12)      // m = 13 > 12
        {
            m =1;       // m = 1
            y++;        // y = 2010
        }
    }
    cout<< "Ket qua: "<< d<< "/"<< m<< "/"<<y;    // Ket qua: 1/1/2010
}
