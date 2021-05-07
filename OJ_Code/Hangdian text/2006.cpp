#include <cstdio>
int main()
{
    int n,sum,m;
    while(scanf("%d",&n) != EOF){
        sum = 1;
        for(int i = 0;i < n;i++){
            scanf("%d",&m);
            if(m%2==1){
                sum *= m;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}