#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = n & -n;
    int cnt = 0;
    for(int i = 0;i <= 30;++i) {
        if(n & (1 << i)) cnt ++;
    }
    for(int i = 0;i <= 30;++i) {
        if(!(ans & (1 << i))) {
            ans += (1 << i);
            break;
        } 
    }
    if(cnt == 1) cout << ans << "\n";
    else cout << (n & -n) << "\n";
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