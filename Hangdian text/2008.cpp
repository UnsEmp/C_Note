#include <cstdio>
int main()
{
    int positive,negative,zero;
    int n;
    double temp;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            break;
        }
        positive = 0;
        negative = 0;
        zero = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf",&temp);
            if(temp > 0)
            {
                positive++;
            }
            else if(temp < 0)
            {
                negative++;
            }
            else
            {
                zero++;
            }
        }
        printf("%d %d %d\n",negative,zero,positive);
    }
}