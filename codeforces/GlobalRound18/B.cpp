#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int prefix[32][N];

void solve() {
    int l, r;
    cin >> l >> r;
    int ma = 0;
    for(int i = 0;i < 32;++i) {
        ma = max(ma, prefix[i][r] - prefix[i][l - 1]);
    }
    cout << (r - l + 1) - ma << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(prefix, 0, sizeof prefix);
    for(int i = 1;i <= 2e5;++i) {
        for(int j = 0;j < 32;++j) {
            if((i >> j) & 1) prefix[j][i] ++; 
        }
    }
    for(int j = 0;j < 32;++j) {
        for(int i = 1;i <= 2e5;++i) {
            prefix[j][i] += prefix[j][i - 1];
        }
    }
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}