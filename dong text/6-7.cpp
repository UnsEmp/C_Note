#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber ( const int N )
{
    int n,k;
    int count=0,cnt=0,cmp;
    for(int i=N;i!=0;i/=10){
        cmp=i%10;
        for(int j=i/10;j!=0;j/=10){
            k=j%10;
            if( cmp==k ){
                count=1;
                break;
            }
        }
        if(count==1){
            break;
        }
    }
    n=sqrt(N);
    if(n*n==N){
        cnt=1;
    }
    if(cnt==1&&count==1){
        return 1;
    }
    else{
        return 0;
    }

}
