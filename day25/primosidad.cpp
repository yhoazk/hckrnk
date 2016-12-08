#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool testPrime( float Xl){
    if(Xl < 0 ) return 0;
    if(!(Xl == (int)Xl)) return 0;
    int iXl = int(Xl);
    int i = 0;
    int lim = int(sqrt(Xl));
    for(i = 3; i <= lim; i += 2){
        if(iXl % i == 0 ){
            return (0); //not prime
        }
    }
    return 1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T = 0;
    float X = 0;
    int iX = 0;
    cin >> T;
    while(T--){
       cin >> X;
        
        iX = int(X);
       if(iX==0 || iX == 1 || (iX > 2 && iX % 2 == 0)){
           cout << "Not prime" << endl;
       }
       else if(iX == 2){
           cout << "Prime" << endl;
       }
       else {
        if(testPrime(X)){
           cout << "Prime" << endl;
        }
        else{

        cout << "Not prime" << endl;
        }

       }
    }
    return 0;
}
