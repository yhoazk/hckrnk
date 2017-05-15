#include <iostream>
/* 
 * 1000000011 5 
 * ee: 5 000 000 058
 * */

using namespace std;

int main(void)
{
    unsigned long long c,r, out;
    cin >> c >> r;
    if(c & 0x01)
    {
        // odd
        out = 10*(c-1)/2 + 2*(r -1);
    }
    else
    {
        // pair
        out = 10*(c-2)/2 + 2*r-1;
    }
    cout << out << endl;
    return 0;
}
