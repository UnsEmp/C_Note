#include <stdio.h>
#define MAX 100010

int a[MAX] = {0}, mp[MAX] = {0};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    int len = 0;
    for(int i = 0, j = 0;j < n && i < n;i++) {
        while(j < n && !mp[a[j]]) mp[a[j++]]++;
        if((j - i) > len) len = j - i;
        mp[a[i]]--;
    }
    printf("%d", len);
    return 0;
}