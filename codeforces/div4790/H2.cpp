#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
ll n;
ll nums[N];
ll tree[N];

ll lowerbit(ll x) {
    return x & -x;
}

void add(ll k, ll x) {
    for(;k <= n;k += lowerbit(k)) {
        tree[k] += x;
    }
}

ll ask(ll k) {
    ll sum = 0;
    for(;k > 0;k -= lowerbit(k)) {
        sum += tree[k];
    }
    return sum;
}

void solve() {
    cin >> n;
    memset(tree, 0, sizeof tree);
    ll ans = 0;
    for(ll i = 1;i <= n;++i) {
        cin >> nums[i];
        ans += (ask(n) - ask(nums[i] - 1));
        add(nums[i], 1);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}