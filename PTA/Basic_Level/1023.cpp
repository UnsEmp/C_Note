#include <cstdio>
#include <algorithm>
#include <cstdbool>
using namespace std;
#define MAX 10

bool compare(int a,int b)
{
    return a < b;
}
int main()
{
    int arr[MAX],sum = 0;
    int count = 0;
    int i,j;
    for(i = 0;i < MAX;i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    int brr[sum],cnt = 0;
    for(i = 0;i < MAX;i++){
        for(j = 0;j < arr[i];j++){
            brr[cnt++] = i;
        }
    }
    sort(brr,brr + sum,compare);
    for(i = 0;i < sum;i++){
        if(brr[i] != 0){
            printf("%d",brr[i]);
            brr[i] = -1;
            break;
        }
    }
    for(i = 0;i < sum;i++){
        if(brr[i] != -1){
            printf("%d",brr[i]);
        }
    }

    return 0;
}