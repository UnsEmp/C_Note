#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> row, col;
        for(int i = 0;i < grid.size();++i) {
            row[grid[i]] ++;
        }
        for(int j = 0;j < grid[0].size();++j) {
            vector<int> arr;
            for(int i = 0;i < grid.size();++i) {
                arr.push_back(grid[i][j]);
            }
            col[arr] ++;
        }
        int ans = 0;
        for(auto &[x, y] : row) {
            ans += col[x] * row[x];
        }
        return ans;
    }
};