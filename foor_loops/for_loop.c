#include <iostream> 
#include <string>

using namespace std;
int main(){
    int a,b,n;
    cout << "sdfsd" << endl;
    cin >> a;
    cin >> b;


    string strings[] = {
        "null",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    cout << a << " " << b << endl;
    string r = "odd";
    for(n=a; n<=b; n++){
         r = "odd";
        if(1 <= n && n <= 9)
        {
            r = strings[n]; 

        }
        else if((n % 2) == 0)
        {
            r = "even";
        }
        cout << r << endl;
    }



    return 0;
}
