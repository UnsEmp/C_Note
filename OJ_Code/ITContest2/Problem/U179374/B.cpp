#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int Min = n, i;
    if(m < n) Min = m;
    for(i = Min;i >= 1;i--) {
        if(n % i == 0 && m % i == 0)
            break;
    }
    printf("%d", i);
    return 0;
}