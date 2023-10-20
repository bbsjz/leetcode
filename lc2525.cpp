#include <iostream>
using namespace std;
string categorizeBox(int length, int width, int height, int mass)
{
    bool bulky=false;
    bool heavy=false;
    int dim=max(length,width);
    dim=max(dim,height);
    dim=max(dim,mass);
    if(dim>=1e4||length*width*height>=1e9) bulky=true;
    if(mass>=100) heavy=true;
    if(bulky&&heavy) return "Both";
    else if(!bulky&&!heavy) return "Neither";
    else if(bulky) return "Bulky";
    else return "Heavy";
} 