// 单点修改， 区间查询
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, m, t;
vector<ll> arr(N);

ll lowbit(ll x) {
    return x & -x;
}

void add(ll k, ll x) {
    for(;k <= n;k += lowbit(k)) arr[k] += x;
}

ll ask(ll k) {
    ll ans = 0;
    for(;k;k -= lowbit(k)) ans += arr[k];
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;++i) {
        cin >> t;
        add(i, t);
    }
    while(m--) {
        ll op, x, y;
        cin >> op >> x >> y;
        if(op == 1) add(x, y);
        else cout << ask(y) - ask(x - 1) << "\n";
    }
    return 0;
}