#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        ll dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1, dp[1][1] = 1;
        for(int i = 2;i <= n;++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
            dp[i][1] = dp[i - 1][0] % mod;
        }
        return (dp[n][0] + dp[n][1]) * (dp[n][0] + dp[n][1]) % mod;
    }
};