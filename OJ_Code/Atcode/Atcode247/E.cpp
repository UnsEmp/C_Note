#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    int ly = 0, ey = 0, ex = 0, mx = 0;
    long long ans = 0LL;
    for(int i = 1;i <= n;++i) {
        int t;
        cin >> t;
        if(t < y) ly = i;
        if(t == y) ey = i;
        if(t == x) ex = i;
        if(t > x) mx = i;
        if(max(ly, mx) > min(ex, ey)) continue;
        ans += (long long)(min(ex, ey) - max(ly, mx));
    }
    cout << ans << "\n";
    return 0;
}