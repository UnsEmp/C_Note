#include <bits/stdc++.h>
using namespace std;

const int ma = INT_MAX;
class Solution {
public:
    int n, m;
    int mp[310][310];
    int dir[5] = {-1, 0, 1, 0, -1};
    vector<vector<int>> firetime = vector<vector<int>>(310, vector<int>(310, ma));
    bool bfs(vector<vector<int>> & grid, int t) {
        if(t >= firetime[0][0]) return false;
        queue<tuple<int, int>> men;
        // for(int i = 0;i < 310;++i) memset(mp[i], 0, sizeof mp[i]);
        // memset(mp, 0, sizeof mp);
        vector<vector<int>> mp(n, vector<int>(m));
        men.push(make_tuple(0, 0));
        mp[0][0] ++;
        while(men.size()) {
            int len = men.size();
            for(int i = 0;i < len;++i) {
                int x, y;
                tie(x, y) = men.front();
                // if(x == n - 1 && y == m - 1 && t <= firetime[x][y]) {
                //     return true;
                // }
                // cout << x << " " << y << " " << t << "\n";
                men.pop();
                for(int j = 1;j < 5;++j) {
                    int nx = x + dir[j - 1], ny = y + dir[j];
                    if(nx == n - 1 && ny == m - 1 && (t + 1) <= firetime[nx][ny]) return true;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && (t + 1) < firetime[nx][ny] && !mp[nx][ny]) {
                        men.push(make_tuple(nx, ny));
                        mp[nx][ny] ++;
                    }
                }
            }
            t ++;
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> mp(n, vector<int>(m));
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    mp[i][j] ++;
                    firetime[i][j] = 0;
                }
            }
        }
        
        int time = 0;
        while(q.size()) {
            int len = q.size();
            for(int i = 0;i < len;++i) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j = 1;j < 5;++j) {
                    int nx = x + dir[j - 1], ny = y + dir[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !mp[nx][ny]) {
                        q.push({nx, ny});
                        mp[nx][ny] ++;
                        firetime[nx][ny] = min(firetime[nx][ny], time + 1);
                    }
                }
                
            }
            time ++;
        }

        int l = -1, r = 1e9;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            // cout << mid << "\n";
            if(bfs(grid, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};