#include <bits/stdc++.h>
using namespace std;

const int N = 7;
int n;
int g[N][N], backup[N][N];

bool judge() {
    for(int i = 0;i < 5;++i) {
        for(int j = 0;j < 5;++j) {
            if(backup[i][j] == 0) return false;
        }
    }
    return true;
}

void solve() {
    int ans = INT_MAX;
    for(int i = 0;i < (1 << 5);++i) {
        int cnt = 0;
        for(int j = 0;j < 5;++j) {
            for(int k = 0;k < 5;++k) {
                backup[j][k] = g[j][k];
            }
        }
        for(int j = 0;j < 5;++j) {
            if((i >> (4 - j)) & 1) {
                cnt ++;
                backup[0][j] ^= 1;
                backup[1][j] ^= 1;
                if(j > 0) backup[0][j - 1] ^= 1;
                if(j < 4) backup[0][j + 1] ^= 1;
            }
        }
        for(int k = 1;k < 5;++k) {
            for(int t = 0;t < 5;++t) {
                if(backup[k - 1][t] == 0) {
                    backup[k - 1][t] ^= 1;
                    backup[k][t] ^= 1;
                    if(t > 0) backup[k][t - 1] ^= 1;
                    if(t < 4) backup[k][t + 1] ^= 1;
                    if(k < 4) backup[k + 1][t] ^= 1;
                    cnt ++;
                }
            }
        }
        if(judge()) {
            ans = min(ans, cnt);
        }
    }
    if(ans <= 6) {
        cout << ans << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
    
}

int main() {
    int _;
    cin >> _;
    getchar();
    while(_--) {
        for(int i = 0;i < 5;++i) {
            for(int j = 0;j < 5;++j) {

                char ch = getchar();
                g[i][j] = ch - '0';
            }
            getchar();
        }
        solve();
    }
    return 0;
}