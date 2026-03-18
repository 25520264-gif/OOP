#include <iostream>
#include <string.h>
using namespace std;

#define mx 400

int main()
{
    char s[mx];
    cout<< "Nhap dung dinh dang-dd/mm/yyyy \n";
    cout<< "Nhap: ";
    cin.getline(s, mx);

    int d = (s[0]-'0')*10 + (s[1]-'0');
    int m = (s[3]-'0')*10 + (s[4]-'0');

    int i = strlen(s) - 1;
    int y = 0;
    int base = 1;

    while(s[i] != '/')
    {
        y += (s[i]-'0') * base;
        base *= 10;
        i--;
    }

    i =6;
    int n =0;
    while(s[i] != '\0')
    {
        n += s[i] - '0';
        i++;
    }

    int songay;
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11: songay =31;break;
        case 4:
        case 6:
        case 8:
        case 10:
        case 12: songay =30;break;
        default:
            {
                if(n % 4 == 0)songay =29;
                else songay = 28;
            }
    }
    d++;
    if(d > songay)
    {
        d = 1;
        m++;
        if(m > 12)
        {
            m =1;
            y++;
        }
    }
    cout<< "Ket qua: "<< d<< "/"<< m<< "/"<<y;
}
