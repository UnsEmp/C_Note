#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d",&a);
    b=a%16;
    a=a/16;
    printf("%d",a*10+b);
}