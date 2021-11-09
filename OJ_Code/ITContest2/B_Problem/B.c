#include <stdio.h>
int main() {
    double h;
    int n;
    scanf("%lf %d", &h, &n);
    for(int i = 0;i < n;i++) {
        h /= 2;
    }
    printf("%.4f", h);
}