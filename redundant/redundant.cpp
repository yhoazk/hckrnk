#include <iostream>
#include <set>
#include <utility>   
using namespace std;

/* The get method is only for c++11, it's not defined before  */
int main() 
{
    int n;
    set<int> db;
    int e; 
    cin >> n;

    pair<int*, bool> test;
    for(; n>0;n--)
    {
        cin >> e;
        if(get<1>(db.insert(e)) == false)
        {
            cout << "REDUNDANT" << endl;
        }
        else
        {
            cout << "ADDED" << endl;
        }
    }
}
