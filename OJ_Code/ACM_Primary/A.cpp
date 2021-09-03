#include <bits/stdc++.h>
using namespace std;
int arr[2000010] = {0};
int main()
{
    double x,y,sum;
    cin >> x >> y;
    sum = pow(100 - x,2) + pow(10 - y,2);
    sum = sqrt(sum);
    if(sum > 10)
        printf("%.3lf",sum - 10);
    else
        printf("0");
    return 0;
}