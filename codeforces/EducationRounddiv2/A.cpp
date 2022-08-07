#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long t = abs(n), dis;
    long long ans = 0;
    if(t == 1) {
        cout << "2\n";
        return ;
    }
    else if(t == 2) {
        cout << "1\n";
        return ;
    }
    if(t % 3 == 0) ans = t / 3;
    else  if(t % 3 == 1) ans = t / 3 - 1 + 2;
    else ans = t / 3 + 1;
    cout << ans << "\n";
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

