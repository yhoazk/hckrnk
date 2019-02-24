#include "longest_uniq_substring.h"

int Solution::lengthOfLongestSubstring(std::string s) {
  int max=0;
  int local = 0;
  for(auto c : s){
    auto it = count.find(c);
    if(count.end() == it){
      //std::cout << "inserted: " << c << '\n'; 
      max++;
    } else {
      local = std::max(local, max);
      max = 1;
      //std::cout << "repeat: " << c << '\n'; 
      count.clear();
    }
    count.insert(std::pair<char, size_t>(c,1));
    local = std::max(local, max);
  } 
  count.clear();
  return local;
}
