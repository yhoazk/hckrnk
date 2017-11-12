#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;    int a0;    int a1;    int a2;
    int n;     int k;     int o = 0; 
    int tmp = 0;
    scanf("%d",&t);
    for(a0 = 0; a0 < t; a0++){
        scanf("%d %d",&n,&k);
        for(a1 = 0; a1 < n; a1++){
            for(a2 = a1+1; a2 < n; a2++){
                tmp = (a1&a2);
                o = (o < tmp)? ((tmp<k)? tmp:o):o;
            }
        }
        printf("%d\n", o);
    }
    return 0;
}
