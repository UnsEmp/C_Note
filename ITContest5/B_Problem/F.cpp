#include <stdio.h>

int hs[15] = {0};
int arr[15];

bool judge(int x) {
    while(x) {
        if(!hs[x % 10]) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
        getchar();
        hs[arr[i]]++;
    }
    int x, y, z, count = 0;
    for(int i = 0;i < n;i++) {
        x = arr[i];
        for(int j = 0;j < n;j++) {
            y = x * 10 + arr[j];
            for(int k = 0;k < n;k++) {
                z = y * 10 + arr[k];
                for(int p = 0;p < n;p++) {
                    for(int q = 0;q < n;q++) {
                        int tmp = arr[p] * 10 + arr[q];
                        if(z * tmp < 10000 && arr[p] * z < 1000 && arr[q] * z < 1000 && judge(arr[p] * z) && judge(arr[q] * z) && judge(tmp * z)) {
                            count++;
                        }
                    }
                } 
            }
        }
    }
    printf("%d", count);
    return 0;
}