#include <cstdio>
int main()
{
    unsigned a;
    scanf("%d",&a);
    if(a<=60){
        printf("Speed: %d - OK",a);
    }
    else{
        printf("Speed: %d - Speeding",a);
    }
}