#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // map<pair<int, int>, int> mp;
    int dfs(int m, int n, int maxcount, int startx, int starty, vector<vector<vector<int>>> & arr) {
        if(startx < 0 || startx >= m || starty < 0 || starty >= n) 
            return 1;
        if(maxcount == 0)
            return 0;
        if (arr[startx][starty][maxcount] != -1) {
            return arr[startx][starty][maxcount];
        }
        if(startx - maxcount >= 0 && startx + maxcount < m && starty - maxcount >= 0 && starty + maxcount < n) 
            return 0;
        int sum = 0;
        for(int i = 0;i < 4;i++) {
            sum = ((sum + dfs(m, n, maxcount - 1, startx + direction[i][0], starty + direction[i][1], arr)) % 1000000007);
        }
        arr[startx][starty][maxcount] = sum;
        return sum;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> arr(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1)));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                for(int t = 0;t <= maxMove;t++) {
                    arr[i][j][t] = -1;
                }
            }
        }
        return dfs(m, n, maxMove, startRow, startColumn, arr);
    }
};

int main() {
    int n, m, move, x, y;
    cin >> n >> m >> move >> x >> y;
    Solution so;
    cout << so.findPaths(n, m, move, x, y) << endl;
    return 0;
}

