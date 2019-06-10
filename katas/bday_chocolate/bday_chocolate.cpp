#include <bits/stdc++.h>

size_t n;
std::vector<size_t> s{0};
size_t d;
size_t m;

#if 0
// remove trailing, leading and duplicated spaces
std::string split_n_strip(std::string line, char splitter =' '){
    std::string cleand;
    // find_if returns only the first element, this means that 
    // in order to filter it has to be run several times until the end 
    // of the iterator
    auto iter = std::find_if(std::begin(line), std::end(line),
                        [](unsigned char c){return std::isspace(c);} /* std::isspace Only receives as an input a unsigned char, otherwise the result is undef */
                        );
    std::cout << typeid(iter).name() << '\n';
    //std::copy(iter, std::end(iter), std::begin(cleand));
    //std::cout << (cleand) << '\n';
    while(iter != std::end(line)){
        std::cout << *iter++ << '-';
    }
    std::cout << '\n';
    return cleand;
}
#endif
/* This only works if there are only 1 space in between the numbrs */
template<typename T, typename S>
std::vector<T> split(const T& in_iter, S splitter){
    std::vector<T> tokens;
    size_t start{0};
    size_t end{0};
    // npos indicates the end of the string aka -1
    while ((end = in_iter.find(" ", start)) != std::string::npos){
        std::cout << "end: " << end << '\n';
        tokens.push_back(in_iter.substr(start, end - start));
        start = end + 1;
    }
    std::cout << "Size of Tokens: " << tokens.size() << '\n';
    return tokens;
}


/* remove duplicated spaces */
template<typename T, typename X>
void dedup(T& cont, X dup){
    auto _start = std::begin(cont);
    // Pitfall the end of the string is here being stored
    // the erase operation moves this pointer, then the pointer 
    // comparison will never be true, as the iterator comparison
    // is address based not value based
    // auto _end = std::end(cont);
    // while (_start != _end{
    while (_start != std::end(cont)){
        // here we are comparing the iterators, whe need to
        // dereference the value pointed by them, even when 
        // the debugger display the value the comparison is 
        // different
        if(*_start == *(_start + 1)){
            cont.erase(_start);
        } else {
            // We only advace if there are no deletions, otherwise
            // the index increments by 2 one for the deletion and
            // one by this increment
            ++_start;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<size_t> cohoc;
    std::string line;

    std::getline(std::cin, line);
    dedup(line, ' ');
    std::cout << line << '\n';
    for(auto c : split(line, ' ')){
        std::cout << "sPLotteddd  : " << c << '\n';
    }

    return 0;
}
