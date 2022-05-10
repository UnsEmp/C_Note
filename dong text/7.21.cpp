#include <stdio.h>
#include <math.h>
int main()
{
    int n,t=0;
    scanf("%d",&n);
    for(int i=1;i<=sqrt(n);i++){
        for(int j=1;j<=sqrt(n);j++){
            if(pow(i,2)+pow(j,2)==n&&i<=j){
                printf("%d %d\n",i,j);
                t=1;
            }
        }
    }
    if(t==0){
        printf("No Solution");
    }
}

