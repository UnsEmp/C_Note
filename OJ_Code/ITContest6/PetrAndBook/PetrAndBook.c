#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[7];
    for(int i = 0;i < 7;i++) scanf("%d", &arr[i]);
    int top = 0;
    while(n - arr[top % 7] > 0) {
        n -= arr[(top++) % 7];
    }
    printf("%d", (top % 7) + 1);
    return 0;
}