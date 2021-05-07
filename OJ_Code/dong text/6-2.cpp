#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */
double f(int n,double a[],double x)
{
    double sum=0,t=x;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                x=1;
            }
            else{
                x*=t;
            }
        }
        sum+=a[i]*x;
    }
    return sum;
}