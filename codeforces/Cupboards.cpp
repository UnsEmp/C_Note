#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left, right;
    int leftSum = 0, rightSum = 0;
    for(int i = 0;i < n;i++) {
        cin >> left >> right;
        leftSum += left;
        rightSum += right;
    }
    int sum = ((leftSum > n / 2)?n - leftSum:leftSum) + ((rightSum > n / 2)?n - rightSum:rightSum);
    cout << sum;
   // (leftSum > n / 2)?n - leftSum:leftSum + (rightSum > n / 2)?n - rightSum:rightSum;
    return 0;
}