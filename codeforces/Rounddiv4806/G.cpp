#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    long long ans = 0, sum = 0;
    for(int i = -1;i < n;++i) {
        long long now = sum;
        for(int j = i + 1;j < min(n, i + 32);++j) {
            now += (nums[j] >> (j - i)); 
        }
        ans = max(ans, now);
        if(i + 1 != n)
        sum += (nums[i + 1] - k);
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