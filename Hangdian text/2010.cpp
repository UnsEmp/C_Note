#include <cstdio>
#define fun(a) (a)*(a)*(a)
int main()
{
    int m,n,sum = 0,count = 0;
    while(scanf("%d %d",&m,&n) != EOF)
    {
        count = 0;
        for(int i = m;i <= n;i++)
        {
            int j = i;
            sum = 0;
            while(j != 0)
            {
                sum += fun(j%10);
                j /= 10;
            }
            if(sum == i)
            {
                if(count == 0)
                {
                    printf("%d",i);
                }
                else
                {
                    printf(" %d",i);
                }
                count++;
            }
        }
        if(count == 0)
        {
            printf("no\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
