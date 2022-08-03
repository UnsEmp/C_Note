#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
char mat[N][N];
int dist[N][N];
bool mp[N][N];
int 
dx[] = {
    -1, -1, 1, 1
},
dy[] = {
    -1, 1, -1, 1
},
ix[] = {
    -1, -1, 0, 0 
},
iy[] = {
    -1, 0, -1, 0
};


int bfs() {
    deque<pair<int,int>> dq;
    int step = 0;
    dist[0][0] = 0;
    dq.push_back({0, 0});
    mp[0][0] = true;
    while(dq.size()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        for(int i = 0;i < 4;++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            int w;
            mp[nx][ny] = true;
            string res = "\\//\\";
            if(mat[x + ix[i]][y + iy[i]] != res[i]) w = 1;
            else w = 0;
            if(dist[x][y] + w < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + w;
                if(w) dq.push_back({nx, ny});
                else dq.push_front({nx, ny});
            }
        }
    }
    if(dist[n][m] != 0x3f3f3f3f) return dist[n][m];
    return -1;
}

void solve() {
    memset(dist, 0x3f, sizeof dist);
    memset(mp, 0, sizeof mp);
    cin >> n >> m;
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            cin >> mat[i][j];
        }
    }
    int t = bfs();
    if(t == -1) cout << "NO SOLUTION\n";
    else cout << t << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}