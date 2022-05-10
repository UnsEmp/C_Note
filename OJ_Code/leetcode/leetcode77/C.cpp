#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt = 0, nm, nn;
    map<pair<int,int>, int> mp, wa;
    int dir[5] = {-1, 0, 1, 0, -1};
    void bfs(int x, int y, int xx, int yy) {
        if(x < 0 || x >= nm || y < 0 || y >= nn || wa[{x, y}]) return ;
        if(!mp[{x, y}]) {
            mp[{x, y}] ++;
            cnt ++;
        }
        int nx = xx + x, ny = y + yy;
        bfs(nx, ny, xx, yy);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        cnt = walls.size() + guards.size();
        nm = m, nn = n;
        for(int i = 0;i < walls.size();++i) {
            wa[{walls[i][0], walls[i][1]}] ++;
            mp[{walls[i][0], walls[i][1]}] ++;
        }
        for(int i = 0;i < guards.size();++i) {
            wa[{guards[i][0], guards[i][1]}] ++;
            // mp[{walls[i][0], walls[i][1]}] ++;
        }
        for(int i = 0;i < guards.size();++i) {
            for(int j = 1;j < 5;++j) {
                bfs(guards[i][0] +  dir[j - 1], guards[i][1] + dir[j], dir[j - 1], dir[j]);
            }
        }
        return n * m - cnt;
    }
};