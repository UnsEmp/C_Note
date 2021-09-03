#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, pmin, pmax;
    int Max = -1, Min = 101;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        if(arr[i] > Max) {
            Max = arr[i];
            pmax = i;
        }
        if(arr[i] <= Min) {
            Min = arr[i];
            pmin = i;
        }
    }
    // cout << pmax << " " << pmin << endl;
    printf("%d",pmax < pmin?pmax + n - pmin - 1:pmax + n - pmin - 2);
    return 0;
}