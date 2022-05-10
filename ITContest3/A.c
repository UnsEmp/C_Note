#include <stdio.h>
int main() {
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);
    if(t == 0) {
        printf("%d", 0);
    }
    else {
        m -= s / t;
        if(s % t != 0) m--;
        if(m < 0) printf("%d", 0);
        else printf("%d", m);
    }
    return 0;
}
