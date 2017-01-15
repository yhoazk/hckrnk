#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <stdio.h>
using namespace std;

class Calculator : public exception{
public:
  /*virtual const char* what() const throw()
  {
    return "n and p should be non-negative";
  }*/
  int power(int n, int p){
      if(n < 0 || p < 0){
        //throw "n and p should be non-negative";
        throw  invalid_argument( "n and p should be non-negative" );
      }
      else{
        return pow(n,p);
      }
    }


};


int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl;
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

}
