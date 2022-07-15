#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
class Solution {
public:
    int n, m;
    // long long dp[1100][1100];
    int dir[5] = {-1, 0, 1, 0, -1};
    long long dfs(vector<vector<int>> &grid ,vector<vector<int>> &dp, int x, int y) {
        if(dp[x][y]) return dp[x][y];
        dp[x][y] = 1;
        for(int i = 1;i < 5;++i) {
            int xx = dir[i - 1] + x, yy = dir[i] + y;
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && grid[x][y] > grid[xx][yy]) {
                dp[x][y] = (dp[x][y] + dfs(grid, dp, xx, yy)) % mod;
            }
        }
        return dp[x][y];
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        // memset(dp, 0, sizeof dp);
        long long sum = 0;
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                long long t = dfs(grid, dp, i, j);
                // cout << t << " ";
                sum = (sum + t) % mod;
            }
            // cout << "\n";
        }
        return sum;
    }
};