#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long dp[N];
void solve() {
    map<int, int> mp;
    int n, m = 0;
    cin >> n;
    for(int i = 1;i <= n;++i) {
        int t;
        cin >> t;
        mp[i] = t;
        if(i == t) m ++;
    }
    long long ans = 0;
    for(int i = 1;i <= n;++i) {
        if(mp[i] == i) continue;
        // cout << i << " " << mp[i] << " " << mp[i] << " " << mp[mp[i]] << "\n";
        if(i == mp[mp[i]]) ans ++;
    }
    // ans -= m;
    // cout << m << " " << ans << " " << "\n";
    ans /= 2;
    memset(dp, 0, sizeof dp);
    for(int i = 1;i <= m;++i) {
        dp[i] = dp[i - 1] + (i - 1);
    }
    cout << ans + dp[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int _;
    // cin >> _;
    // while(_--) {
        solve();
    // }
    return 0;
}