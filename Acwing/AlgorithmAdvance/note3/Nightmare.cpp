#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 810;
int n, m;
char grid[N][N];
int dire[5] = {-1, 0, 1, 0, -1};
bool stm[N][N], stw[N][N];

int dis(int i, int j, int k, int l) {
    return abs(i - k) + abs(j - l);
}

void solve() {
    scanf("%d %d", &n, &m);
    queue<pair<int, int>>  women, men;
    vector<pair<int, int>> ghost;
    getchar();
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            grid[i][j] = getchar();
            if(grid[i][j] == 'G') women.push({i, j});
            else if(grid[i][j] == 'M') men.push({i, j});
            else if(grid[i][j] == 'Z') ghost.push_back({i, j});
        }
        getchar();
    }

    int step = 0;
    memset(stw, 0, sizeof stw);
    memset(stm, 0, sizeof stm);
    stw[women.front().first][women.front().second] = true;
    stm[men.front().first][men.front().second] = true;
    while(men.size() || women.size()) {
        int len;
        for(int k = 0;k < 3;++k) {
            len = men.size();
            for(int i = 0;i < len;++i) {
                auto [x, y] = men.front();
                men.pop();
                if(dis(ghost.front().first, ghost.front().second, x, y) <= (step + 1) || dis(ghost.back().first, ghost.back().second, x, y) <= (step + 1)) continue;
                for(int j = 1;j < 5;++j) {
                    int nx = x + dire[j - 1], ny = y + dire[j];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || stm[nx][ny] || grid[nx][ny] == 'X' || dis(ghost.front().first, ghost.front().second, nx, ny) <= 2 * (step + 1) || dis(ghost.back().first, ghost.back().second, nx, ny) <= 2 * (step + 1)) continue;
                    stm[nx][ny] = true;
                    men.push({nx, ny});
                }
            }
        }

        len = women.size();
        for(int i = 0;i < len;++i) {
            auto [x, y] = women.front();
            women.pop();
            if(dis(ghost.front().first, ghost.front().second, x, y) <= 2 * (step + 1) || dis(ghost.back().first, ghost.back().second, x, y) <= (step + 1)) continue;
            for(int j = 1;j < 5;++j) {
                int nx = x + dire[j - 1], ny = y + dire[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || stw[nx][ny] || grid[nx][ny] == 'X' || dis(ghost.front().first, ghost.front().second, nx, ny) <= (step + 1) || dis(ghost.back().first, ghost.back().second, nx, ny) <= 2 * (step + 1)) continue;
                if(stm[nx][ny]) {
                    printf("%d\n", step + 1);
                    return ;
                }
                stw[nx][ny] = true;
                women.push({nx, ny});
            }
        }

        step ++;
    }
    printf("-1\n");
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _;
    scanf("%d", &_);
    getchar();
    while(_--) {
        solve();
    }
    return 0;
}



