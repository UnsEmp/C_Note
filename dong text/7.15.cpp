#include <stdio.h>
int main()
{
    double a=1,b;
    double sum=1;
    double n=1,m=1;
    double p=3,q=3;
    scanf("%lf",&b);
    while(a>b){
        a=n/p;
        sum+=a;
        m++;
        q+=2;
        n=n*m;
        p=p*q;
    }
    printf("%lf",2*sum);

    return 0;
}
