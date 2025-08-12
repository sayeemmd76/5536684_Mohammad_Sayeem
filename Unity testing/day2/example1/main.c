#include <stdio.h>
#include "demo.h"
int main(){
    int a=10, b=20, c, d;
    c=sum(a,b);
    d=square(a);
    printf("sum is:%d\n",c);
    printf("square is:%d\n",d);
    return 0;
}