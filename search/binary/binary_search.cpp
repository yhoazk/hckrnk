#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

ssize_t binary_search_iter(std::vector<size_t>& A, size_t n, size_t x){
    size_t p = 0; // Points to the start of the array or sub array
    size_t r = n -1; // points to the end of the array or sub array
    while(p <= r){
        size_t q = (p+r) / 2;

        if(A[q] == x) return q;

        if(A[q] > x){
            // the upper subset does not contain X
            r = q - 1;
        } 
        else {
            // the lower subset does not contain x
            p = q + 1;
        }
    }
    return -1;
}


ssize_t binary_search_recur(std::vector<size_t>& A, size_t p, size_t r, size_t x){
    if(p > r) return -1;
    size_t q = (p+r) / 2;
    if(A[q] == x) {
        return q;
    }
    else  {
        if(A[q] > x){
            return binary_search_recur(A, p, q-1, x);
        }
        else {
            return binary_search_recur(A, q+1, r, x);
        }
    }
}

int main(int argc, char const *argv[])
{
    ssize_t search;
    std::vector<size_t> search_space{0, 9, 11, 12, 20, 25, 36, 39, 40, 45, 99, 123};
    for (auto& e : search_space) {
        std::cout << std::setw(4) << e;
    }
    std::cout << std::endl;
    std::cin >> search;
    std::stringstream pos;
    auto k = binary_search_iter(search_space, search_space.size(), search); // this will have to be modified when we use iterators
    auto m = binary_search_recur(search_space, 0, search_space.size(), search); // this will have to be modified when we use iterators
    if(k != m ){
        std::cerr << "ERRROR!!!!\n\n";
        return 2;
    }
    if (k == -1) return 1;
    do{
        pos << "    ";
    }while(k--);
    auto last = pos.tellp();
    pos.seekp(last-1);
    pos.write("^",1);
    std::cout << pos.str() << "\n";
    return 0;
}
