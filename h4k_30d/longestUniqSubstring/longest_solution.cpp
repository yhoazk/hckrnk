
#include <bits/stdc++.h>
#include "longest_uniq_substring.h"

int main(int argc, char const *argv[])
{
  using namespace std;
  Solution s;
  cout << "Len: " << s.lengthOfLongestSubstring("abcabcbb") << "==3\n";
  cout << "Len: " << s.lengthOfLongestSubstring("pwwkew") << "==3\n";
  cout << "Len: " << s.lengthOfLongestSubstring("bbbbb") << "==1\n";
  cout << "aok\n"; 
  return 0;
}