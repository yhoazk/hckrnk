#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
    std::unordered_map<char, size_t> count;
public:
    Solution(): count({}){};
    int lengthOfLongestSubstring(const std::string);
};