#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#define MAXSIZE 100000

int main()
{
    int HeadAddress,N,K,sum = 0,i;
    scanf("%d %d %d",&HeadAddress,&N,&K);
    int head,temp,data[MAXSIZE],list[MAXSIZE],next[MAXSIZE],result[MAXSIZE];
    for(int i = 0;i < N;i++){
        scanf("%d",&temp);
        scanf("%d %d",&data[temp],&next[temp]);
    }
    temp = HeadAddress;
    int count = K-1;
    while(temp != -1){
        list[sum++] = temp;
        temp = next[temp];
    }
    for(i = 0;i < sum;i++)
        result[i] = list[i];
    for(i = 0;i < sum - sum%K;i++)
        result[i] = list[i/K*K + K - 1 - i%K];
    for(i = 0;i < sum-1;i++)
        printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
    printf("%05d %d -1",result[i],data[result[i]]);
    return 0;
}