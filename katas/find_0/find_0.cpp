#include <bits/stdc++.h>

size_t input = (1ul << 34ul);
ssize_t sinput = (1ul << 34ul);

template<typename T>
T find_1(T n){
  T c = 0;
  while(n >>= 1){
    ++c;
  }
  return c;
}


int main(){
  //std::cout << std::hex << find_1(input) << std::endl;
  std::cout << std::bitset<64>( input ) << std::endl;
  std::cout << ( input ) << std::endl;
  std::cout << std::bitset<64>( 1-input ) << std::endl;
  std::cout << ( 1-input ) << std::endl;
  std::cout << std::bitset<64>( input ) << std::endl;
  std::cout <<"Number of bits set to 1: " << (__builtin_popcountl(input) ) << std::endl;
  std::cout <<"Number of bits set to 0 L->R: " << (__builtin_clz(input) ) << std::endl;
  std::cout << ( input ) << std::endl;
  std::cout <<"Number of bits set to 0 R->L: " << (__builtin_ffsl(input) -1 ) << std::endl;
  std::cout <<"Number of bits set to 0 R->L: " << (__builtin_ctzl(input) ) << std::endl;
  std::cout <<"Number of bits set to fnc 0 R->L: " << (find_1(input) ) << std::endl;
  std::cout << ( input ) << std::endl;
  //std::cout << std::bitset<64>( find_1(input) ) << std::endl;
  //std::cout << std::bitset<64>( find_1(sinput) ) << std::endl;
  return 0;
}
