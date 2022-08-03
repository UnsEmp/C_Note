#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    long long ans = 0;
    int i = 0;
    while(i < n && nums[i] == 0) i++;
    while(i < n - 1) {
        if(nums[i]) ans += nums[i];
        else ans ++;
        i++;
    }
    cout << ans << "\n";
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