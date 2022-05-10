#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 210;
ll n, a, b, ans = LONG_LONG_MAX;
vector<ll> nums(N);
bool st[N];
void dfs(ll idx, ll count) {
    if(st[idx]) return ; 
    if(ans < count) return ;
    if(idx > n || idx < 1) return ;
    if(idx == b) {
        ans = min(ans, count);
        return ;
    }
    if(idx > n) return ;
    st[idx] = true;
    dfs(idx + nums[idx], count + 1);
    dfs(idx - nums[idx], count + 1);
    // st[idx] = false;
}

signed main() {
    cin >> n >> a >> b;
    for(ll i = 1;i <= n;++i) cin >> nums[i];
    dfs(a, 0);
    if(ans == LONG_LONG_MAX) cout << "-1" << "\n";
    else cout << ans << "\n";
    return 0;
}