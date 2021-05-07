#include <cstdio>
int main()
{
    char a,b,c,ch;
    while(scanf("%c%c%c",&a,&b,&c)!=EOF)
    {
        if(a>b&&a>c)
        {
            ch = a;
            a = c;
            c = ch;
        }
        else if(b>a&&b>c)
        {
            ch = b;
            b = c;
            c = ch;
        }
        if(a>b)
        {
            ch = b;
            b = a;
            a = ch;
        }
        printf("%c %c %c\n",a,b,c);
        getchar();
    }
    return 0;
}