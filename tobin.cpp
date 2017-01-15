#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* Prints the binary representation of the input value expected in Dec */



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char inVal[32] = {0};
    char outVal[33] = {0};
    int i = 0;
    int j = 0;
    int Val;
    int k;
    char t[5] = {0};

    cin >> t;
    i = atoi(t);
    while(i--){
        cin >> inVal;
        Val = atoi(inVal);
        k = Val;
        while(k){ k = k >> 1; j++;}
        j = j-1;
        while(j >= 0){
            outVal[j--] = (Val % 2) + 0x30;
            Val /= 2;
            if(Val == 0 ) break;
        }
        //outVal[0] = '\0';
        cout << outVal << endl;
        j = 0;
        fill(outVal, outVal+33, 0);
    }
    return 0;
}
