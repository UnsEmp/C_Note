#include <stdio.h>
int main()
{
    int a[2][2]={1,2,3,4};
    for(int i=0;i<4;i++){
        printf("%ld ",*(a+i));
    }
}