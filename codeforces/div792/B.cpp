#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long x, y, z, t;
    t = max(a, max(b, c));
    z = t, y = t + b, x = y + a;
    // t = 1;
    // while(z <= y) {
    //     z += a * t;
    //     t ++;
    // }
    cout << x << " " << y << " " << z << "\n";
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