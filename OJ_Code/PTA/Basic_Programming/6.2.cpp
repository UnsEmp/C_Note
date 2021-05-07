#include <stdio.h>
int main ()
{
    char *a;
    char b[20];
    a=b;
    scanf("%[^\n]",a);
    *(a+2)='o';
    printf("%s",a);
    return 0;
}
