#include <cstdio>
#include <cmath>
int main()
{
    int x1,y1,x2,y2,x,y;
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2) != EOF)
    {
        x = x1 - x2;
        y = y1 - y2;
        x *= (double)x;
        y *= (double)y;
        printf("%.2lf\n",sqrt(x+y));
    }
}