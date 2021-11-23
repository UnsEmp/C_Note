#include <cstdio>

int main()
{
    int A,B,D;
    int sum,count = 0,bit = 0;
    int arr[40];
    scanf("%d %d %d",&A,&B,&D);
    sum = A + B;
    while(sum){
        bit = sum%D;
        arr[count++] = bit;
        sum = sum/D;
    }
    if(A + B){
        for(int i = count-1;i >= 0;i--){
            printf("%d",arr[i]);
        }
    }
    else{
        printf("0");
    }
    return 0;
}