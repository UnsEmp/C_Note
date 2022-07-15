#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int dp[n + forget + 1];
        memset(dp, 0, sizeof dp);
        dp[1] = 1;
        for(int i = 1;i <= n;++i) {
            for(int j = i + delay;j < i + forget && j <= n;++j) {
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }
        int ans = 0;
        for(int i = n - forget + 1;i <= n;++i) ans = (ans + dp[i]) % mod;
        return ans;
    }
};