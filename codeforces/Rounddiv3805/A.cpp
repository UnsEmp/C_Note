#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, res = 1;
    cin >> n;
    while(res * 10 <= n) {
        res *= 10;
    }
    cout << n - res << "\n";
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