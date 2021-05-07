#include <stdio.h>
int main()
{
    int n,u,d;
    int x,v=u,t=0;
    scanf("%d %d %d",&n,&u,&d);
    while(1){
        x+=u;
        t++;
        if(x>=n){
            break;
        }
        x-=d;
        t++;
    }
    printf("%d",t);
    return 0;
}
