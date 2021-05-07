#include <stdio.h>
int bei(int a,int b)
{
    int c;
    while(a%b){
        c=a;
        a=b;
        b=c%b;
    }
    return b;
}
int main()
{
    int a1,b1,a2,b2,n,m;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    n=b1;
    m=b2;
    a1=a1*m;
    b1=b1*m;
    a2=a2*n;
    b2=b2*n;
    n=a1+a2;
    m=b1;
    if(n%m==0){
        printf("%d",n/m);
    }
    else{
        printf("%d/%d",n/bei(n,m),m/bei(n,m));
    }
}