#include <iostream>
using namespace std;
int passThePillow(int n, int time)
{
    int xunhuanjie;
    xunhuanjie = time / (n - 1);
    if (time % (n - 1) != 0)
        xunhuanjie++;
    int pos = time % (n - 1);
    if (xunhuanjie % 2 == 1)
    {
        if (pos == 0)
            return n;
        else
            return pos + 1;
    }
    else
    {
        if (pos == 0)
            return 1;
        else
            return n - pos;
    }
}

int main()
{
    cout << passThePillow(6, 7);
    return 0;
}