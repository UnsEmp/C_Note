#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int nums[N][N];
int n, m;
int lp[N][N], rp[N][N];

int cal(int x, int y) {
    int lx = x, ly = y, rx = x, ry = y;
    while(lx + 1 <= n && ly + 1 <= m) {
        lx ++;
        ly ++;
    }
    while(rx + 1 <= n && ry - 1 >= 1) {
        rx ++;
        ry --;
    }
    return lp[lx][ly] + rp[rx][ry] - nums[x][y];
}

void solve() {
    cin >> n >> m;
    memset(lp, 0, sizeof lp);
    memset(rp, 0, sizeof rp);
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;++j) {
            int t;
            cin >> t;
            nums[i][j] = t;
            lp[i][j] = lp[i - 1][j - 1] + t;
            rp[i][j] = rp[i - 1][j + 1] + t;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;j++) {
            ans = max(ans, cal(i, j));
        }
    }
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