#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prifixrow1(n + 1), prifixcol1(m + 1), prifixrow2(n + 1), prifixcol2(m + 1);
        for(int i = 1;i <= n;++i) {
            int num2 = 0, num5 = 0;
            prifixrow1[i].push_back(0);
            prifixrow2[i].push_back(0);
            for(int j = 1;j <= m;++j) {
                int t = grid[i - 1][j - 1];
                while(t % 2 == 0) {
                    num2 ++;
                    t /= 2;
                }
                while(t % 5 == 0) {
                    num5 ++;
                    t /= 5;
                }
                if(t > 1) {
                    if(t == 2) num2 ++;
                    else if(t == 5) num5 ++;
                }
                prifixrow1[i].push_back(num2);
                prifixrow2[i].push_back(num5);
            } 
        }
        for(int j = 1;j <= m;++j) {
            int num2 = 0, num5 = 0;
            prifixcol1[j].push_back(0);
            prifixcol2[j].push_back(0);
            for(int i = 1;i <= n;++i) {
                int t = grid[i - 1][j - 1];
                while(t % 2 == 0) {
                    num2 ++;
                    t /= 2;
                }
                while(t % 5 == 0) {
                    num5 ++;
                    t /= 5;
                }
                if(t > 1) {
                    if(t == 2) num2 ++;
                    else if(t == 5) num5 ++;
                }
                prifixcol1[j].push_back(num2);
                prifixcol2[j].push_back(num5);
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;++i) {
            for(int j = 1;j <= m;++j) {
                ans = max(ans, min(prifixrow1[i][j] + prifixcol1[j][i - 1], prifixrow2[i][j] + prifixcol2[j][i - 1]));
                ans = max(ans, min(prifixrow1[i][j] + prifixcol1[j][n] - prifixcol1[j][i], prifixrow2[i][j] + prifixcol2[j][n] - prifixcol2[j][i]));
                ans = max(ans, min(prifixrow1[i][m] - prifixrow1[i][j - 1] + prifixcol1[j][i - 1], prifixrow2[i][m] - prifixrow2[i][j - 1] + prifixcol2[j][i - 1]));
                ans = max(ans ,min(prifixrow1[i][m] - prifixrow1[i][j - 1] + prifixcol1[j][n] - prifixcol1[j][i], prifixrow2[i][m] - prifixrow2[i][j - 1] + prifixcol2[j][n] - prifixcol2[j][i]));
            }
        }
        return ans;
    }
};