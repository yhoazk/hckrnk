#include "solar_doomsday.h"


int main(){
    long area;
    std::cin >> area;
    std::vector<unsigned long> result = naive_answer(area);
    //std::cout << "vector s: " << result.size() << '\n';
    for(auto e : result){
        std::cout << e << ", ";
    }    
    std::cout << '\n';
    return 0;
}