#include <cstdio>
int main()
{
    int n,t=0;
    scanf("%d",&n);
    long long a,b,c;
    while(t!=n){
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a+b>c){
            printf("Case #%d: true\n",t+1);
        }
        else{
            printf("Case #%d: false\n",t+1);
        }
        t++;
    }
}