#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int a,b,c;
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(((a+b)>c) && ((a+c)>b) && ((b+c)>a))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}