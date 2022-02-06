#include <iostream>
#include <vector>
#include <functional>

std::vector<int*> filter(std::vector<int> data, std::function<bool(int)>&& rule) {
    std::vector<int*> result;
    for (int i=0; i < data.size(); ++i ) {
        std::cout << "D: " << data[i] << " Addr: " << &data[i];
        if (rule(data[i])) {
            std::cout << " OK";
            result.push_back(&data[i]);
        }
        std::cout << std::endl;
    }
    return result;
}

int main () {
    std::vector<int> v{3, 5, 1,2,3,4};

    auto res{filter(v, [](int v){ return !!(v & 0b000000001);})};
    std::cout << "\nFiltered\n";
    for (const auto& v : res) {
        std::cout << "V: " << *v << std::endl;
    }
    std::cout << "\nUpdate\n";
    v.push_back(20);

    for (const auto& v : res) {
        std::cout << "V: " << *v << std::endl;
    }

    return 0;
}