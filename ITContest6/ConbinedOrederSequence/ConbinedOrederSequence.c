#include <stdio.h>
#define MAX 210

int arr[MAX * 2], brr[MAX];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int t = 0;t < n;t++) scanf("%d", &arr[t]);
    for(int t = 0;t < m;t++) scanf("%d", &brr[t]);
    int i = n - 1, j = m - 1;
    for(int t = m + n - 1;t >= 0;t--) {
        if(i >= 0 && j >= 0) {
            if(arr[i] > brr[j]) arr[t] = arr[i--];
            else arr[t] = brr[j--];
        }
        else if(i >= 0) arr[t] = arr[i--];
        else arr[t] = brr[j--];
    }
    for(int t = 0;t < n + m;t++) printf("%d ", arr[t]);
    return 0;
}