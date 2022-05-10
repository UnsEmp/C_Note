#include <stdio.h>

int gcd(int a, int b) {
    if(a%b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    printf("%d",gcd(n, m));
    return 0;
}