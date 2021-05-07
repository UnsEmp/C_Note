#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit ( const int N, const int D )
{
    int t=N,count=0;
    if(t<0){
        t=-t;
    }
    if(t==0){
        count++;
    }
    else{
        while(t!=0){
            if(t%10==D){
                count++;
            }
            t/=10;
        }
    }
    return count;
}