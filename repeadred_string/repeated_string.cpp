#include <bits/stdc++.h>

using namespace std;

/**
 * Function to find the number of characters c in the 
 * string s for the range [start, end]
*/
long num_c_in_s(char c, string& s, long start, long end)
{
  return std::count(s.begin(), s.begin()+end, c);
}

long repeatedString(string s, long n) {
    long ains = num_c_in_s('a', s, 0, s.length());
    long  full = n/s.length();
    long part = n % s.length();
    return (full * ains) + num_c_in_s('a',s,0,part);
}

int main() {
    string s;
    cin >> s;
    long n;
    cin >> n;
    long result = repeatedString(s, n);
    cout << result << endl;
    return 0;
}
