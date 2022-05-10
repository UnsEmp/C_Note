#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2 * 1e5 + 10;
vector<ll> w(N);
void solve() {
    ll n;
    cin >> n;
    for(ll i = 0;i < n;++i) {
        cin >> w[i];
    }
    if(n == 1) {
        cout << "0" << "\n";
        return ;
    }
    ll l = 0, r = n - 1, ans = 0;
    ll as = w[0], bs = w[n - 1];
    while(l < r) {
        if(as == bs) {
            ans = max(ans, l + 1 + (n - r));
            as += w[++l];
        }
        else if(as < bs) {
            as += w[++l];
        }
        else {
            bs += w[--r];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}