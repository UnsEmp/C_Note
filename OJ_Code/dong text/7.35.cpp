#include <stdio.h>
int f(int a,int b)
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
    int n;
    scanf("%d",&n);
    int a[n],b[n],yin,sum1=0,sum2=0;
    scanf("%d/%d",&a[0],&b[0]);
    for(int i=1;i<n;i++){
        scanf("%d/%d",&a[i],&b[i]);
        a[i]=a[i]*b[i-1]+a[i-1]*b[i];
        b[i]=b[i]*b[i-1];
        yin=f(a[i],b[i]);
        a[i]/=yin;
        b[i]/=yin;
    }
    b[n-1]=b[n-1]*n;
    yin=f(a[n-1],b[n-1]);
    a[n-1]/=yin;
    b[n-1]/=yin;
    if(a[n-1]%b[n-1]==0){
        printf("%d",a[n-1]);
    }
    else{
        printf("%d/%d",a[n-1],b[n-1]);
    }
}