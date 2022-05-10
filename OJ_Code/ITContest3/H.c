#include <stdio.h>
#define MAX 10010
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0, count = 0;
    int i = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < i;j++) {
            sum += i;
            count++;
            if(count == n) break;
        }
        if(count == n) break;
    }
    printf("%d", sum);
    return 0;
}