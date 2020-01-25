#include <iostream>
#include <iomanip>
#include <vector>

void insertion_sort(std::vector<size_t>& A, size_t n){
    size_t smallest;
    for (size_t i = 0; i < n; i++){
        smallest = i;
        for (size_t j = i; j < n; j++){
            if(A[smallest] > A[j])
                smallest = j;
        }
        auto tmp = A[smallest];
        A[smallest] = A[i];
        A[i] = tmp;
    }
    
}

template<typename t>
void show(t& A){
    for (auto &&i : A){
        std::cout << std::setw(4) << i;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<size_t> search_space{10, 92, 1, 21, 20, 25, 6, 3, 140, 5, 99, 123};
    show(search_space);
    insertion_sort(search_space, search_space.size());
    show(search_space);
    return 0;
}
