#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = int(1e9 + 7);

ll quick_pow(ll n, int p) {
    if(p == 1) return n;
    if(p % 2 == 0) {
        ll prevP = quick_pow(n, p / 2);
        return (prevP * prevP) % MOD;
    }
    return (n * quick_pow(n, p - 1)) % MOD;
}


int main()
{   
    char c;
    int p = 1, ans = 1;
    while (cin >> c) {
        ans = (ll(ans) * quick_pow(ll(c - '0'), p)) % MOD;
        p++; 
    }
    cout << ans << endl;
    return 0;
}