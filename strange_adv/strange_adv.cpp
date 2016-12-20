#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int i = 0; 
int users_like = 0;


void calc_users_like(int users)
{
    int k =0;
    if(i < n)
    {
        i++;
        k = users >> 1;
        users_like += k;
        calc_users_like(k*3);
    }
    else
    {
        return;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> n;
    calc_users_like(5);

    cout << users_like;
    return 0;
}
