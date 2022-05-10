#include <cstdio>
int f(int a,int b)
{
    int t;
    while(a%b){
        t=b;
        b=a%b;
        a=t;
    }
    return b;
}
int main()
{
    int a,b,c;
    scanf("%d/%d",&a,&b);
    c=f(a,b);
    printf("%d/%d",a/c,b/c);
    return 0;
}