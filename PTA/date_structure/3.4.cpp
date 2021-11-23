#include <cstdio>
int main()
{
    int n,start = 0,stop = 0,count = 0,max = 0;
    int temp=0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i++)
    scanf("%d",&arr[i]);
    for(int i = 1;i < n;i++){
        if(arr[i-1] < arr[i]){
            count++;
        }
        if(count > max){
                start = temp;
                max = count;
                stop = i;
        }
        if(arr[i-1] >= arr[i]){
            count  = 0;
            temp = i;
        }
    }
    for(int i = start;i <= stop;i++){
        printf("%d",arr[i]);
        if(i != stop){
            printf(" ");
        }
    }
}