// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 9;
int sum = 0, ans = -1;
int grid[N][N];
int row[N], col[N], pos[N][N], cnt[1 << N], bit[1 << N];
bool st[N][N];

inline int lowerbit(int x) {
    return x&-x;
}

inline void init() {
    for(int i = 0;i < N;++i) row[i] = col[i] = (1 << N) - 1;
    for(int i = 0;i < N;++i) {
        for(int j = 0;j < N;++j) {
            pos[i][j] = (1 << N) - 1;
        }
    }
    for(int i = 0;i < 1 << N;++i) {
        int s = 0;
        for(int j = i;j; j -= lowerbit(j)) s ++;
        cnt[i] = s;
    }
    bit[1] = 1;
    for(int i = 1;i < N;++i) {
        bit[1 << i] = i + 1;
    }
}

inline int getNum(int x, int y) {
    return row[x] & col[y] & pos[x / 3][y / 3];
}

inline void trans(int x, int y, int t) {
    row[x] ^= (1 << (t - 1));
    col[y] ^= (1 << (t - 1));
    pos[x / 3][y / 3] ^= (1 << (t - 1));
}

inline int cal() {
    int x = 0, y = 0, res, count = 1, k = 6;
    memset(st, 0, sizeof st);
    res = k * grid[0][0];
    st[0][0] = true; 
    while(count < N * N) {
        while(y + 1 < N && !st[x][y + 1]) res += k * grid[x][++y], st[x][y] = true, ++count;
        while(x + 1 < N && !st[x + 1][y]) res += k * grid[++x][y], st[x][y] = true, ++count;
        while(y - 1 >= 0 && !st[x][y - 1]) res += k * grid[x][--y], st[x][y] = true, ++count;
        while(x - 1 >= 0 && !st[x - 1][y]) res += k * grid[--x][y], st[x][y] = true, ++count;
        ++k; 
    }
    return res;
}

void dfs() {
    if(sum == 0) {
        ans = max(ans, cal());
        return ;
    }
    int x, y, z = 10;
    for(int i = 0;i < N;++i) {
        for(int j = 0;j < N;++j) {
            if(grid[i][j]) continue;
            int t = cnt[getNum(i, j)];
            if(t < z) {
                z = t;
                x = i, y = j;
            }
        }
    }
    z = getNum(x, y);
    while(z) {
        int t = bit[lowerbit(z)];
        grid[x][y] = t;
        trans(x, y, t);
        --sum;
        dfs();
        trans(x, y, t);
        ++sum;
        grid[x][y] = 0;
        z -= lowerbit(z);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(int i = 0;i < N;++i) {
        for(int j = 0;j < N;++j) {
            cin >> grid[i][j];
            if(grid[i][j]) {
                row[i] ^= (1 << (grid[i][j] - 1));
                col[j] ^= (1 << (grid[i][j] - 1));
                pos[i / 3][j / 3] ^= (1 << (grid[i][j] - 1));
            }
            else ++ sum;
        }
    }
    dfs();
    cout << ans << "\n";
}