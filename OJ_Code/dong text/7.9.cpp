#include <cstdio>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b)printf("C");
    if(b==c)printf("A");
    if(a==c)printf("B");
    return 0;
}