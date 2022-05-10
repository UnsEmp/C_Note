#include <cstdio>
int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    int sum = 0;
    int arr[n+1] = {0}; //存储每一位的值，可能会进位
    int temp = 0; //用来作为中间变量储存每一位计算的值
    int bit = 0; //负责进位
    if(n == 0){
        printf("0");
        return 0;
    }
    for(int i = n;i >= 0;i--){ 
        temp = i * a + bit;
        arr[i] = temp%10;
        bit = temp/10;
    }
    if(arr[0] != 0){   //如果进位了就输出它的值
        printf("%d",arr[0]); 
    }
    for(int i = 1;i < n + 1;i++){
        printf("%d",arr[i]);
    }
    return 0;
}