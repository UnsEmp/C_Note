#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int mod = 998244353;
long long dp[N][N][N], prefix[N];


void solve() {
    memset(prefix, 0, sizeof prefix);
    // memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1;i <= n;++i) {
        // long long t;
        // cin >> t;
        cin >> nums[i];
        // prefix[i] = prefix[i - 1] + nums[i];
    }
    long long ans = 0;
    for(int i = 1;i <= n;++i) {
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;

        for(int j = 0;j < n;++j) {
            for(int k = 0;k <= i && k <= j;++k) {
                for(int l = 0;l < i;++l) {
                    dp[j + 1][k][l] = (dp[j + 1][k][l] + dp[j][k][l]) % mod;
                    if(k != i) dp[j + 1][k + 1][(l + nums[j + 1]) % i] = (dp[j + 1][k + 1][(l + nums[i]) % i] + dp[j][k][l]) % mod;
                }
            }
        }
        ans = (ans + dp[n][i][0]) % mod;
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}