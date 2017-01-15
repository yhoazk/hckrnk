#include <iostream>

using namespace std;

/*  Prints the calssical stair problem given an input int 
 *  e.g.:
5
----#
---##
--###
-####
#####
 *
 *  */




int main(){
    int n,x,y;
    cin >> n;
    x = n;
    y = n;
    while(x-- > 0){
        while(y-- > 1){
            cout << '-';
        }
        y = n - x;
        while(y--){ cout << '#';}
        cout <<  endl;
        y = x;
    }
    return 0;
}
