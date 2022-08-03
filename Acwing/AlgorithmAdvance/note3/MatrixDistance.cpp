// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int mat[N][N], ans[N][N];
bool mp[N][N];
queue<pair<int, int>> q;
int dir[5] = {-1, 0, 1, 0, -1};

void bfs() {
    int step = 0;
    while(q.size()) {
        int len = q.size();
        for(int i = 0;i < len;++i) {
            auto [x, y] = q.front();
            q.pop();
            ans[x][y] = step;
            for(int j = 1;j < 5;++j) {
                int nx = x + dir[j - 1], ny = y + dir[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || mp[nx][ny]) continue;
                q.push({nx, ny});
                mp[nx][ny] = true;
            }
        }
        step ++;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    getchar();
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            mat[i][j] = getchar() - '0';
            if(mat[i][j]) {
                q.push({i, j});
                mp[i][j] = true;
            }
        }
        getchar();
    }
    bfs();
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}