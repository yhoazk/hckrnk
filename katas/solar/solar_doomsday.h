#include <bits/stdc++.h>

std::vector<unsigned long> naive_answer(unsigned long area){
    std::vector<unsigned long> solution;
    unsigned long sq = 0;
    unsigned long rem_sq = 0;
    while(area > 0){
        sq = std::sqrt(area); // return the int part of the sqrt
        rem_sq = std::pow(sq,2);
        solution.push_back(rem_sq);
        area -= rem_sq;
    }
    return solution;
}