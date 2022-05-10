#include <cstdio>
#include <cmath>
int main()
{
    int m,n,t;
    int odd,even;
    while(scanf("%d %d",&m,&n) != EOF)
    {
        odd = 0;
        even = 0;
        if(m > n)
        {
            t = m;
            m = n;
            n = t;
        }
        for(int i = m;i <= n;i++)
        {
            if(i%2 == 0)
            {
                even += pow(i,2);
            }
            else
            {
                odd += pow(i,3);
            }
        }
        printf("%d %d\n",even,odd);
    }
    return 0;
}