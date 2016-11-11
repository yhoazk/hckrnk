#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int v, n, l, *arr, *arr_start;
    char *arrchar, *endptr = 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%d\n", &v);
    scanf("%d\n", &n);
    l = n; // store for 2nd loop
    arrchar = malloc(n*6); // each number can be 6 chars each _-1000
    arr = malloc(n*sizeof(int)); // store the ints
    arr_start = arr;
// ONLY GCC/Linux    getline(&arrchar, &l, stdin );
    fgets(arrchar, n*6, stdin);

    *arr++ = strtol(arrchar, &endptr, 10);
    for(n--;n>0;n--)
    {
        *arr++ = strtol(endptr, &endptr, 10);
    }
    
    for(n=0;n<l;n++){
        if(v == arr_start[n]){
            printf("%d\n",n);
            n=l;
        }
    }
    return 0;
}

