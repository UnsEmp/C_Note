#include <bits/stdc++.h>
using namespace std;












typedef long long ll;
const int N = 1000000007;

ll quick_mul(ll a, ll b, ll mod) {
    for(int i = 0;i < 31;++i) {
        if(b & 1) a = a * (1 << i) % mod;
    }
    return a;
}

ll comb(ll a, ll b, ll mod) {
    b = min(b, a - b);
    ll molecule = 1, denominator = 1, n = b; // 分子，分母
    for(int i = 0;i < n;++i) {
        // molecule = molecule * (a - i) ;
        molecule = quick_mul(molecule, a - i, mod);
        // denominator = denominator * (b - i);
        denominator = quick_mul(denominator, b - i, mod);
    }
    return molecule / denominator;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        ll a, b;
        cin >> a >> b;
        cout << comb(a, b, N) << "\n";
    }
    return 0;
}