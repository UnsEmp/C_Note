#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i) {
        int cnt = 0;
        if(i % 4 == 1 || i % 4 == 0) {
            cnt = 1;
        }
        for(int j = 1;j <= m;++j) {
            if(j % 4 == 1) cout << cnt << " ";
            else if(j % 4 == 2) cout << (cnt ^ 1) << " ";
            else if(j % 4 == 3) cout << (cnt ^ 1) << " ";
            else cout << cnt << " ";
        }
        cout << "\n";
    }
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