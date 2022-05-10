#include <cstdio>
int  main()
{
    int y,f,n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(98*j-199*i==n){
                printf("%d.%d",i,j);
                cnt=1;
            }
        }
    }
    if(cnt==0)
    {
        printf("No Solution");
    }
}