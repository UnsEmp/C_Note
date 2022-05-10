#include <cstdio>
#include <cmath>
double fun(int n)
{
    double sum = 0;
    for(int i = 1;i <= n;i++)
    {
        sum += 1.0/i*pow(-1,i+1);
    }
    return sum;
}
int main()
{
    int m,n;
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&n);
        printf("%.2lf\n",fun(n));
    }
    return 0;
}