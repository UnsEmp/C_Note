#include <stdio.h>
#define MAX 310
int n, a[MAX], b[MAX];

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        scanf("%d", &n);
        for(int i = 0;i < n;i++) scanf("%d", &a[i]);
        int l = 0, r = n - 1, count = 0;
        while(l <= r) {
            if((count) % 2 == 0) b[count++] = a[l++];
            else  b[count++] = a[r--];
        }
        for(int i = 0;i < n;i++) printf("%d%c", b[i], i == n - 1?'\n':' ');
    }
}