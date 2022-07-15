#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    int ans = 0;
    if(k == 1) {
        for(int i = 1;i < n - 1;i += 2) {
            ans ++;
        }
        cout << ans << "\n";
    }
    else {
        int a = 0, b = 0;
        for(int i = 1;i < n - 1;++i) {
            if(nums[i - 1] + nums[i + 1] < nums[i]) {
                a ++;
            }
        } 
        // for(int i = 2;i < n - 1;++i) {
        //     if(nums[i - 1] + nums[i + 1] < nums[i]) {
        //         b ++;
        //     }
        // }
        cout << max(a, b) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}