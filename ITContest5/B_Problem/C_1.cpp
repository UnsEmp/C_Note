#include <stdio.h>
#include <string.h>

const int N = 10010, len = 1510;
char s[N][len];
int main() {
    int n;
    int count = 0; //记录不同字符串的个数
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%s", s[i]);
        int j;
        for(j = 0;j < i;j++) {
            if(!strcmp(s[i], s[j])) break;      
        }
        if(j == i) count++;
    }
    printf("%d", count);
    return 0;
}