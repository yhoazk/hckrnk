#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getHourGlassSum()
{

}



int main()
{
    vector< vector<int> > arr(6,vector<int>(6));

    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int y_offset = 0;
    int x_offset = 0;
    int sum = 0;
    int max = -INT32_MAX;
    while((y_offset + 3 ) <= 6)
    {
        while((x_offset +3) <= 6)
        {
            sum = arr[y_offset][x_offset] +  arr[y_offset][x_offset+1] +  arr[y_offset][x_offset+2]\
                            +  arr[y_offset+1][x_offset+1] \
                 + arr[y_offset+2][x_offset] +  arr[y_offset+2][x_offset+1] +  arr[y_offset+2][x_offset+2];
//            cout << sum << endl;
            if (sum > max){ max=sum;}
            x_offset++;
        }
//        cout << "__" << endl;
        x_offset = 0;
        y_offset++;
    }

    cout << max << endl;
    return 0;
}

