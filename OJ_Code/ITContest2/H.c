#include <stdio.h>
int main() {
    int _;
    while(_--) {
        int n;
        scanf("%d", &n);
        int arr[12];
        for(int i = 0;i < 12;i++) scanf("%d", &arr[i]);
        for(int i = 0;i < n - 1;i++) {
            for(int j = 0;j < n - i;j++) {
                if(arr[i] > arr[j]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        int count = 0, top = 11;
        while(n) {
            n -= arr[]
        }
    }
}