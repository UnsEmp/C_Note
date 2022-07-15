#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    // int grid[n][m];
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            cin >> grid[i][j];
        }
    }
    int l = 0, r = m - 1;
    while(l + 1 < m && grid[0][l] <= grid[0][l + 1]) {
        l ++;
    }
    while(r - 1 >= 0 && grid[0][r - 1] <= grid[0][r]) {
        r --;
    }
    bool flag = true;
    // if(l >= m && r < 0) cout << 1 << " " << 1 << "\n";
    // else if(l < m && r >= 0) {
        if(!(l == m - 1 && r == 0)) {
            for(int t = 0;t < n;++t) {
                swap(grid[t][l], grid[t][r]);
            }
        }

        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                if(j && grid[i][j] < grid[i][j - 1]) {
                    flag = false;
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag) {
            if(l == m - 1 && r == 0) {
                cout << 1 << " " << 1 << "\n";
                return ;
            }
            cout << l + 1 << " " << r + 1 << "\n";
        }
        else cout << "-1" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}