/* Create a templated max function */

#include <iostream>
// The auto resolution only works with C++14
template <typename T, typename R>
auto max(T a, R b){
  return b < a? a:b;
}

int main(){
  std::cout << "max(1,2):" << max(1 , 2) << "\n";
  std::cout << "max(1.1,2):" << max(1.1 , 2) << "\n";
  std::cout << "max(a,3):" << max('a' , 3) << "\n";
  std::cout << "max('a','b'):" << max('a' ,'b' ) << "\n";
  std::cout << "max(-1,1):" << max(-1 , 1) << "\n";
  std::cout << "max(1,-1):" << max(1 , -1) << "\n";
}
