#include <stdio.h>
#define MAX 110
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[MAX], count = 1, num = n;

    for(int i = 0;i < n;i++) arr[i] = i + 1;

    for(int i = 0;num;i++) {
        if(arr[i % n] == -1) continue;
        if(count % m == 0) {
            printf("%d ", arr[i % n]);
            arr[i % n] = -1;
            num--;
        }
        count++;
    }
    return 0;
}