#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    bool flag = false;
    cin >> n;
    long long arr[3],sum;
    for(int i = 1;i <= n;i++){
        cin.clear();
        scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2]);
        sum = arr[0] + arr[1];
        if(arr[0] > 0 && arr[1] > 0 && sum < 0)
            flag = true;
        else if(arr[0] < 0 && arr[1] < 0 && sum >= 0)
            flag = false;
        else if(sum > arr[2])
            flag = true;
        else
            flag = false;

        if(flag)
            cout << "Case #" << i << ": " << "true" << endl;
        else
            cout << "Case #" << i << ": " << "false" << endl;
    }
    return 0;
}