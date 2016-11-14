#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n, a_i; 
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for( a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }

    while(n--){
        printf("%d\n",a[n]);
    }


    return 0;
}
