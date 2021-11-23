#include <cstdio>

int HashTable[1001] = {0};

int main()
{
    int n;
    int troop,team,score;
    int temp,max = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d-%d %d",&troop,&team,&score);
        HashTable[troop] += score;
        if(HashTable[troop] > max){
            max = HashTable[troop];
            temp = troop;
        }
    }
    printf("%d %d",temp,max);
    return 0;
}