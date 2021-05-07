#include <cstdio>
#include <cmath>
int main()
{
    double n;
    while(scanf("%lf",&n) != EOF)
    {
        printf("%.2lf\n",fabs(n));
    }
}