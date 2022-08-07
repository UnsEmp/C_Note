#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n;
        n = s.size();
        int dp[30];
        memset(dp, 0, sizeof dp);
        for(int i = 0;i < n;++i) {
            int ch = s[i] - 'a';
            int t = 0;
            for(int j = 0;j < 26;++j) {
                // if(abs(s[i] - 'a' - j) <= k) {
                //     dp[s[i] - 'a'] ++;
                // }
                if(abs(ch - j) <= k)
                t = max(t, dp[j] + 1);
            } 
            dp[ch] = max(dp[ch], t);
        }
        int ma = 0;
        for(int i = 0;i < 26;++i) ma = max(ma, dp[i]);
        return ma;
    }
};