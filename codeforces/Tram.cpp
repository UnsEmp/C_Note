#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left, add, Max;
    int sum = 0;
    while(n--) {
        cin >> left >> add;
        sum -= left;
        sum += add;
        Max = max(sum, Max);
    }
    cout << Max;
    return 0;
}