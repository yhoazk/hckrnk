#include <bits/stdc++.h>

std::string input;

/*
class enum: unsigned char {
  i='i',
  d='d',
  s='s',
  o='o',
};
*/
int main(){
  std::cout << "rnn" << std::endl;
  std::cin >> input;
  std::vector<long long> res;
  long long acc = 0;
  for(auto c : input){
    switch(static_cast<unsigned char>(c)){
      case 'i':
        acc++;
        break;
      case 'd':
        acc--;
        break;
      case 's':
        acc = acc*acc;
        break;
      case 'o':
        res.push_back(acc);
        break;
    }
  }
  for(auto e : res){
    std::cout << e << " : ";
  }
  return 0;
}
