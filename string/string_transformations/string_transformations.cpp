#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// https://www.hackerrank.com/contests/code-cpp-may-2015/challenges/string-transformations
int main(){
    string inString;
    int Q,a,b;
    
    cin >> inString;
    cin >> Q;

    cout << inString << endl;
    cout << Q << endl;
    for(; Q > 0; Q--)
    {
        cin >> a >> b;
        reverse(&inString[a], &inString[b+1]);
        cout << inString << endl;
    }

    
}
