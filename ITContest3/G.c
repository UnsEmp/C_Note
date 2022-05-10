#include <stdio.h>
#define MAX 110
int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX], brr[MAX] = {0};
    for(int i = 0;i < n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            if(arr[j] < arr[i]) brr[i]++;
        }
    }
    for(int i = 0;i < n;i++) {
        printf("%d ", brr[i]);
    }
    return 0;
}