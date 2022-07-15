#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    vector<ll> prifix;
    prifix.push_back(0);
    for(int i = 0;i < n;++i) prifix.push_back(prifix[i] + nums[i]);
    ll ans = 0;
    // cout << prifix[n] << "\n";
    for(int i = k;i <= n;++i) {
        // cout << prifix[i] - prifix[i - k] << "\n";
        ans = max(ans, (prifix[i] - prifix[i - k] + (k - 1) * (1 + k - 1) / 2));
    }
    if(n >= k) cout << ans << "\n";
    else {
        ans = prifix[n] + (k - n) + 1LL * (n - 1) * (k - n) + 1LL * (1 + (n - 1)) * (n - 1) / 2;
        cout << ans << "\n";
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