#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x = max(x - a, 0);
    y = max(y - b, 0);
    if(x + y <= c) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}