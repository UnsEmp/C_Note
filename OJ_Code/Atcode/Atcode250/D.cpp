
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6;

bitset<N> st;

void sieve(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (st[i]) continue;
        for (ll j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

signed main() {
    ll n;
    vector <ll> primes;
    cin >> n;
    sieve(1e6);
    for(ll i = 2;i <= 1e6;i++)
        if(!st[i]) primes.push_back(i);
    ll ans = 0;
    for(int i = 0;i < primes.size();++i) {
        ll p = primes[i];
        ll l = i, r = primes.size() - 1;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            ll q = primes[mid] * primes[mid] * primes[mid];
            if(q <= n / p) l = mid;
            else r = mid - 1; 
        }
        ans += (l - i);
    }
    cout << ans << "\n";
    return 0;
}