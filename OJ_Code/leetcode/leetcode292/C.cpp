#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

class Solution {
public:
    ll mod = 1e9 + 7;
    ll N = 1e5 + 10;
    ll countTexts(string pre) {
        ll n = pre.size();
        ll f[N], g[N];
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;
        for(ll i = 4;i <= n;++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % mod;
        }
        ll ans = 1;
        for(ll i = 0;i < n;++i) {
            ll j = i + 1;
            while(j < n && pre[j] == pre[i]) j++;
            if(pre[i] == '7' || pre[i] == '9') ans = (ans * g[j - i]) % mod;
            else ans = (ans * f[j - i]) % mod;
            i = j - 1;
        }
        return ans;
    }
};