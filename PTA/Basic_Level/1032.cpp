#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int max=-1,sum[100010]={0},numb,score,k;
    for(int i=0;i<n;i++){
        scanf("%d %d",&numb,&score);
        sum[numb]+=score;
    }
    for(int i=0;i<100010;i++){
        if(max<sum[i]){
            max=sum[i];
            k=i;
        }
    }
    printf("%d %d",k,max);
    return 0;
}