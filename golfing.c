/*
 * golfing
 * */

#include <stdio.h>
/* The next function calculates a the list of pair numbers which yield the parameter N 
 * The function only prints if the modulo operation returns 0
 * j++*j<N <- a short version to calculate only upto sqrt(N)
 * */
f(N,j){for(j=1;j++*j<N;)N%j||printf("|%d,%d",j,N/j);}
main()
{

    f(9);
    printf("\n\n");
    int j= 0;
    // the next printf instruction is not exec as the 3%2 returns 1, then is != and the switch or
    // executes both statements to verify if any of them is true, !=0 is interpreted as true
    // and 0 is interpreted as false
    printf("Value of true  :: %d\n", 0==0); // Value of true :: 1
    printf("Value of false :: %d\n", 0!=0); // Value of false :: 0
    // For the case 3%2=1, thus true, as it finds a first true there's no point in executing the second
    // operation of the switch ||
    3%2||printf("3mod :: %d\n", 3%2); 
    !3%2||printf("!3mod :: %d\n", 3%2); 
    // for this case 4%2=0, interpreted as false, then to verify the second statement of hte switch
    // the print is executed.
    4%2||printf("4mod :: %d\n", 4%2); 
}
