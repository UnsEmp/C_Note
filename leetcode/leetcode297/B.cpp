#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        for(int i = 0;i < m;++i) f[0][i] = grid[0][i];
        for(int i = 0;i < n - 1;++i) {
            for(int j = 0;j < m;++j) {
                for(int k = 0;k < m;++k) {
                    f[i + 1][k] = min(f[i + 1][k], f[i][j] + moveCost[grid[i][j]][k]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i < m;++i) ans = min(ans, f[n - 1][i] + grid[n - 1][i]);
        return ans; 
    }
};

void print(int t) {
    cout << t << "\n";
    for(int i = 31;i >= 0;--i) {
        cout << ((t >> i) & 1) << "";
    }
    cout << "\n";
}

int main() {
    int t = 5;
    print(t);
    print(~t);
    return 0;
}