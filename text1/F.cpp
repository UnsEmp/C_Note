#include <stdio.h>

int main()
{
    long long arr[50];
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3;i < 41;i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10000;
    }
    long long sum = 0;
    for(int i = 1;i < 41;i++) {
        sum += arr[i];
    }
    printf("s=%lld", sum);
    return 0;
}