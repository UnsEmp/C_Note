#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> nums(n + 1, vector<char>(n + 1));
    // int nums[n][n]
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= n;++j) {
            cin >> nums[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n / 2;++i) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        x1 = y1 = i;
        x2 = x1, y2 = n - y1 + 1;
        x3 = n - x1 + 1, y3 = y1;
        x4 = x3, y4 = y2;
        while(y1 < y2) {
            int t = nums[x1][y1] + nums[x2][y2] + nums[x3][y3] + nums[x4][y4] - 4 * ('0');
            ans += min(t, 4 - t);
            y1 ++;
            x2 ++;
            x3 --;
            y4 --;
        }
    }
    // for(int i = 1;i <= n / 2;++i) {
    //     // for(int j = 1;j <= n / 2;++j) {
    //     //     int t = 0;
    //     //     t = nums[i][j] + nums[i][n - j + 1] + nums[n - i + 1][j] + nums[n - i + 1][n - j + 1] - 4 * (int)('0');
    //     //     ans += min(t, 4 - t);
    //     // }
    //     int t = 0;
    //     t = nums[i][i] + nums[i][n - i + 1] + nums[n - i + 1][i] + nums[n - i + 1][n - i + 1] - 4 * (int)('0');
    //     ans += min(t, 4 - t);
    //     for(int j = i + 1;j <= n / 2;++j) {
    //         t = nums[i][j] + nums[i][n - j + 1] + nums[n - i + 1][j] + nums[n - i + 1][n - j + 1] + nums[j][i] + nums[n - j + 1][i] + nums[j][n - i + 1] + nums[n - j + 1][n - i + 1] - 8 * (int)('0');
    //         ans += min(t, 8 - t);
    //     }
    // }
    // if(n & 1) {
    //     int x, y;
    //     x = y = n / 2 + 1;
    //     int cnt = 1;
    //     while(x - cnt >= 1) {
    //         int res = nums[x - cnt][y] + nums[x + cnt][y] + nums[x][y - cnt] + nums[x][y + cnt] - 4 * (int)('0');
    //         ans += min(res, 4 - res);
    //         cnt ++;
    //     }
    // }
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