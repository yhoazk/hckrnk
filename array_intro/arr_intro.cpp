#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//https://www.hackerrank.com/challenges/arrays-introduction?h_r=next-challenge&h_v=zen

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    cin >> n;
    i=n;
    int* arr= new int[n];
    for(;n>0;n--){
        cin >> arr[n];
    }
    
    for(n++;n<=i;n++){
        cout << arr[n] << " ";
    }
    return 0;
}
