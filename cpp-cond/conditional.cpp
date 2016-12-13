#include <iostream>
#include <string>
using namespace std;
string k [] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};


int main(){
    int n;
    cin >> n;
    if(n<10)
    {
        cout << k[n] << endl;
    }else 
    {
        cout << "Greater than 9" << endl;
    }
}
