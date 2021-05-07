#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    char arr[12];
    char *p;
    p = arr;
    for(int i = 0;i < n;i++){
        scanf("%s",p);
        printf("6%s",p+6);
        printf("\n");
    }
}