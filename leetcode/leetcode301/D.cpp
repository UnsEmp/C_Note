#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mod = 1e9 + 7;
    int idealArrays(int n, int ma) {
        int dp[n + 1][ma + 1];
        memset(dp, 0, sizeof dp);
        vector<vector<int>> fac(ma + 1);
        for (int i = 1; i <= ma; i++)
            for (int j = i; j <= ma; j += i) {
                // cout << i << " " << j << "\n";
                fac[j].push_back(i);
            }
        
        for(int i = 1;i <= ma;++i) dp[1][i] = 1;
        for(int i = 2;i <= n;++i) {
            for(int j = 1;j <= ma;++j) {
                // int r = j;
                // dp[i][j] = (dp[i][j] + dp[i - 1][1]) % mod;
                for(int k = 0;k < fac[j].size();++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][fac[j][k]]) % mod;
                }
            } 
        }
        long long ans = 0;
        for(int i = 1;i <= ma;++i) ans = (ans + dp[n][i]) % mod;
        return ans;
    }
};

// int main() {
//     int K = 5;
//     vector<vector<int>> fac(6);
//     for (int i = 1; i <= K; i++)
//         for (int j = i; j <= K; j += i) {
//             cout << i << " " << j << "\n";
//             fac[j].push_back(i);
//         }
//     return 0;
// }