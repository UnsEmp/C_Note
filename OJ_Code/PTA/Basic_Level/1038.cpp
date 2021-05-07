#include <cstdio>
#define MAX 126

int HashTable[MAX] = {0};

int main()
{
    int n;
    scanf("%d",&n);
    int score;
    for(int i = 0;i < n;i++){
        scanf("%d",&score);
        HashTable[score]++;
    }
    int k;
    scanf("%d",&k);
    scanf("%d",&score);
    for(int i = 0;i < k-1;i++){
        printf("%d ",HashTable[score]);
        scanf("%d",&score);
    }
    printf("%d",HashTable[score]);
    return 0;
}