#include <cstdio>
int n,len = 1;
int arr[5001][50001] = {{0}};
void f(int k)
{
    int i;
    for(i = 1;i <= len;i++){
        arr[k][i] = arr[k-1][i] + arr[k-2][i];
    }
    for(i = 1;i <= len;i++){
        if(arr[k][i] >= 10){
            arr[k][i+1] += arr[k][i]/10;
            arr[k][i] %= 10;
            if(arr[k][len+1])
            len++;  
        }
    }
}
int main()
{
    scanf("%d",&n);
    arr[1][1] = 1;
    arr[2][1] = 2;
    for(int i = 3;i <= n;i++){
        f(i);
    }
    for(int i = len;i > 0;i--){
        printf("%d",arr[n][i]);
    }
    return 0;
}