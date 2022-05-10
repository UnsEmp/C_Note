#include <stdio.h>
int f(int n,int m)
{
    int cnt=1;
    for(int i=2;i<=n;i++){
        if((n%i==0)&&(m%i==0)){
            cnt=i;
        }
    }
    return cnt;

}
int main()
{
    int a,b,t;
    scanf("%d/%d",&a,&b);
    if(a>b){
        t=a;
        a=b;
        b=t;
    }
    t=f(a,b);
    printf("%d/%d",a/t,b/t);
    return 0;
}