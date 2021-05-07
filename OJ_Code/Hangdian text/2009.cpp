#include <cstdio>
#include <cmath>
int main()
{
    double n,sum;
    int m;
    while(scanf("%lf %d",&n,&m) != EOF)
    {
        sum = 0;
        sum += n;
        for(int i = 0;i < m-1;i++)
        {
            sum += sqrt(n);
            n = sqrt(n);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}