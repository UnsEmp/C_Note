#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;


template <typename T, typename W>
vector<int> KMP(T &p, T &s, W m, W n) {
    unordered_map<W, W> ne;
    vector<W> ans;
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

class Solution {
public:
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> w;
        int n = piles.size();
        for(int i = 0;i < n;++i) {
            w[i].push_back(0);
            for(int j = 0;j < piles[i].size();++j) {
                w[i].push_back(w[i][j] + piles[i][j]);
            }
        }
        vector<int> dp(n + 1);
        for(int i = 1;i <= n;++i) {
            for(int j = k;j >= 0;--j) {
                for(int t = 0;t < w[i].size();++t) {
                    dp[j] = max(dp[j], dp[j - t] + w[i][t]);
                }
            }
        }
        return dp[n];
    }
};