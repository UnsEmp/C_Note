#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;++i) cin >> a[i];
    int ma = 0;
    for(int i = 0;i < n;++i) {
        cin >> b[i];
        ma = max(ma, a[i] - b[i]);
    }
    bool flag = true;
    for(int i = 0;i < n;++i) {
        if(max(0, a[i] - ma) != b[i]) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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