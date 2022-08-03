#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, H, M;
    cin >> n >> H >> M;
    int mi = INT_MAX, mon = H * 60 + M;
    for(int i = 0;i < n;++i) {
        int h, m, t;
        cin >> h >> m;
        t = h * 60 + m;
        mi = min(mi, ((t - mon) + 1440) % 1440);
    }
    cout << mi / 60 << " " << mi % 60 << "\n";
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