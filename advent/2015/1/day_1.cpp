#include <iostream>
#include <map>
#include <string>

void part1() {
    std::string input;
    std::cin >> input;
    int k{0};
    for (const auto& c : input) {
        if('(' == c) {
            k++;
        } else {
            k--;
        }
    }
    std::cerr << std::to_string(k) << std::endl;
}

void part2(){
    std::string input;
    std::cin >> input;
    int k{0};
    int pos{0};
    for (const auto& c : input) {
        pos++;
        if('(' == c) {
            k++;
        } else {
            if (k == 0) {
                std::cerr << "Pos: " << pos << std::endl;
            }
            k--;
            
        }
    }
    std::cerr << std::to_string(k) << std::endl;
}


int main() {
    part1(); //232
    part2(); //1783

}