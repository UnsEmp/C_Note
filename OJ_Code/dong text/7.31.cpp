#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    int n,t=0;
    scanf("%[^\n]",a);
    scanf("%d",&n);
    n=n%strlen(a);
    char *p;
    p=a+n;
    for(int i=0;i<strlen(a);i++){
        if(*p=='\0'){
            p=a;
        }
        printf("%c",*p);
        p++;
        
    }
}