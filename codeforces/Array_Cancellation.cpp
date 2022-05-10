#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 10;
long long n;
vector<long long> arr(N);
signed main() {
    long long _;
    cin >> _;
    while(_--) {
        cin >> n;
        long long positive = 0,negative = 0;
        for(int i = 0;i < n;++i) {
            cin >> arr[i];
        }
        long long ans = 0;
        for(int i = n - 1;i >= 0;--i) {
            if(arr[i] <= 0) negative += arr[i];
            else positive += arr[i];
            if(positive > 0) {
                if(positive >= abs(negative)) { //如果正数没有用完，就不能再用来消去前面的负数了
                    positive += negative;
                    negative = 0;
                    ans += positive;
                    positive = 0;
                }
                else {
                    negative += positive;
                    positive = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}