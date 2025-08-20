#include <stdio.h>
#include "demo.h"
#include "unity.h"
void setUp(){}
void tearDown(){}
void test_sum(){
    TEST_ASSERT_EQUAL(3,sum(1,2));
}
int main(){
    int a=10, b=20, c, d;
    c=sum(a,b);
    d=square(a);
    printf("sum is:%d\n",c);
    printf("square is:%d\n",d);
    UNITY_BEGIN();
    RUN_TEST(test_sum);
    return UNITY_END();
}