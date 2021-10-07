#include <stdio.h>
int main() {
    int n, tmp;
    scanf("%d %d", &n, &tmp);
    if(n == 1) printf("%d\n",tmp);
    else if(n == 2) printf("%lf",(double)tmp);
    else printf("%c", (char)tmp);
    return 0;
}