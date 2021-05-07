#include <cstdio>
int main()
{
    int n,m;
    char b;
    scanf("%d %c %d",&n,&b,&m);
    if(b=='+')printf("%d",n+m);
    else if(b=='-')printf("%d",n-m);
    else if(b=='*')printf("%d",n*m);
    else if(b=='/')printf("%d",n/m);
    else if(b=='%')printf("%d",n%m);
    else printf("ERROR");
    return 0;
}