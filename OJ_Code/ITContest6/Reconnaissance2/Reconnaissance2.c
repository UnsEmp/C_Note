#include <stdio.h>
#include <math.h>
#define MAX  110

int a[MAX];
int Max = 1000;
int max(int a, int b) {
    return a > b?a:b;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    int l, r;
    for(int i = 1;i < n;i++) {
        int tmp = abs(a[i] - a[i - 1]);
        if(abs(a[i] - a[i - 1]) < Max) {
            Max = abs(a[i] - a[i - 1]);
            l = i;
            r = i + 1;
        }
    }
    if(abs(a[0] - a[n - 1]) < Max) {
        l = 1, r = n;
    }
    printf("%d %d\n", l, r);
    return 0;
}