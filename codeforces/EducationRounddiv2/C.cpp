#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll m;
int grid[4][N];
bool st[4][N];
int dir[5] = {-1, 0, 1, 0, -1};
void solve() {
    memset(grid, 0, sizeof grid);
    // memset(dp, 0x3f, sizeof dp);
    memset(st, 0, sizeof st);
    cin >> m;
    for(int i = 1;i <= 2;++i) {
        for(int j = 1;j <= m;++j) {
            cin >> grid[i][j];
        }
    }
    queue<pair<ll, ll>> q;
    q.push({1, 1});
    // st[1]
    ll step = 0;
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        st[x][y] = true;
        int t = INT_MAX, tx, ty;
        for(ll i = 1;i < 5;++i) {
            ll nx = x + dir[i - 1], ny = y + dir[i];
            if(nx < 1 || nx > 2 || ny < 1 || ny > m || st[nx][ny]) continue;
            if(grid[nx][ny] < t) {
                t = grid[nx][ny];
                tx = nx, ty = ny;
            }
        }
        if(t != INT_MAX) {
            q.push({tx, ty});
            if(step >= grid[tx][ty]) ++ step;
            else step = grid[tx][ty] + 1;
            // st[tx][ty] = true;
        }
    }
    cout << step << "\n";
    // dp[1][1] = 0;
    // for(ll i = 1;i <= 2;++i) {
    //     for(ll j = 1;j <= m;++j) {
    //         // if(i == 1 && j == 1) continue;
    //         ll t = 0;
    //         for(ll k = 0;k < 2;++k) {
    //             ll nx = i + dir[k][0], ny = dir[k][1] + j;
    //             if(nx < 1 || nx > 2 || ny < 1 || ny > m) continue;
    //             if(dp[i][j] >= grid[nx][ny]) {
    //                 dp[nx][ny] = min(dp[nx][ny], dp[i][j] + 1 + t);
    //             }
    //             else {
    //                 dp[nx][ny] = min(dp[nx][ny], grid[nx][ny] + 1 + t);
    //             }
    //             t += 2;
    //             // dp[nx][ny] = min(dp[i][j] + grid[nx][ny] + 1, dp[nx][ny]);
    //         }
    //         // t = 0;
    //         // for(ll k = 0;k < 2;++k) {
    //         //     ll nx = i + dir[k][0], ny = dir[k][1] + j;
    //         //     if(nx < 1 || nx > 2 || ny < 1 || ny > m) continue;
    //         //     if(dp[i][j] >= grid[nx][ny]) {
    //         //         dp[nx][ny] = min(dp[nx][ny], dp[i][j] + 1 + (k == 0));
    //         //     }
    //         //     else {
    //         //         dp[nx][ny] = min(dp[nx][ny], grid[nx][ny] + 1 + (k == 0));
    //         //     }
    //         //     t ++;
    //         //     // dp[nx][ny] = min(dp[i][j] + grid[nx][ny] + 1, dp[nx][ny]);
    //         // }
    //     }
    // }
    // for(ll i = 1;i <= 2;++i) {
    //     for(ll j = 1;j <= m;++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // ll ans = 0;
    // for(ll i = 1;i <= 2;++i) {
    //     for(ll j = 1;j <= m;++j) {
    //         ans = max(ans, dp[i][j]);
    //     }
    // }
    // cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}