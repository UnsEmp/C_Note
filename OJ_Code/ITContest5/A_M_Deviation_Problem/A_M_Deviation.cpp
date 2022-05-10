#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i < n;i++) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        if((arr[0] + arr[1] + arr[2]) % 3 == 0) printf("0\n");
        else printf("1\n");
        
    }
    return 0;
}