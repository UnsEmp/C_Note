#include <cstdio>
#include <cstdlib>
bool JudgePrimeNumber(int x)
{
    int cnt = 0;
    for(int i = 2;i < x;i++){
        if(x % i == 0){
            cnt = 1;
        }
    }
    if( cnt ){
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    int x,y;
    int temp = 0;
    while(true){
        temp = 0;
        scanf("%d %d",&x,&y);
        if(x == 0 && y == 0){
            break;
        }
        for(int i = x;i <= y;i++){
            if( !JudgePrimeNumber(i*i+i+41) ){
                temp = 1;
                break;
            }
        }
        if(temp)
        printf("Sorry\n");
        else
        printf("OK\n");
    }
    return 0;
}