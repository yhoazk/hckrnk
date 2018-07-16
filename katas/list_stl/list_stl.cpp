#include <iostream>
#include <list>

size_t fib_rec(size_t n){
  //std::cout << n << std::endl;
  if(n < 2){
    return n;
  } else {
    return fib_rec(n-1) + fib_rec(n-2);
  }
}


size_t fib_sec(size_t n){
  size_t a=0, b=1, c;
  for(size_t i=0; i<n; ++i){
    c = a+b;
    a=b;
    b=c;
  }
  return a;
}






int main(){
  int i;
  std::list<size_t> ll = {};
  std::cin >> i;
  std::cout <<  fib_rec(i) << std::endl;
  std::cout <<  fib_sec(i) << std::endl;
  return 0;
}
