#include <stdio.h>

int main() {
    int n;
    bool flag = true;
    scanf("%d", &n);
    for(int i = 2;i < n;i++) {
        if(n % i == 0) flag = false;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}