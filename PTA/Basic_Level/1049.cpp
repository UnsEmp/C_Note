#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    double temp, sum = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lf",&temp);
        sum += (temp * (i * (n - i + 1)));
    }                                   
    printf("%.2lf",sum);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    return 0;
}