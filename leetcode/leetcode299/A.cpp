#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        int i = 0, j = 0;
        while(i < n && j < n) {
            flag[i][j] = true;
            if(grid[i][j] == 0) return false;
            i ++, j ++;
        }
        i = 0, j = n - 1;
        while(i < n && j >= 0) {
            flag[i][j] = true;
            if(grid[i][j] == 0) return false;
            i ++, j --;
        }
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < n;++j) {
                if(flag[i][j]) continue;
                if(grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};