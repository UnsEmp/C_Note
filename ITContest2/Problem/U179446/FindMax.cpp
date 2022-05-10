#include <stdio.h>

int main() {
    int n, tmp;
    int Max = -1000000;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &tmp);
        if(Max < tmp) {
            Max = tmp;
        }
    }
    printf("%d", Max);
    return 0;
}

// int main() {
//     for(int i = 0;i < 100;i++) {
//         printf("%d ", rand() % 100000);
//     }
//     return 0;
// }