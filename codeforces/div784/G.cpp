#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 60, M = 60;
int n, m;
vector<vector<char>> g(N, vector<char>(M));

void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return ;
    int nx = x + 1, ny = y;
    if(nx >= 0 && nx < n && g[nx][ny] == '.') {
        g[x][y] = '.';
        dfs(nx, ny);
    }
    else {
        g[x][y] = '*';
    }
}

void solve() {
    // int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            cin >> g[i][j];
        }
    }
    for(int i = n - 1;i >= 0;--i) {
        for(int j = m - 1;j >= 0;--j) {
            if(g[i][j] == '*') dfs(i, j);
        }
    }
    // cout << "----" << "\n";
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}