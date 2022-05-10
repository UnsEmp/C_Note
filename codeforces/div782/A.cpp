#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    int m = r / (b + 1);
    string s, ans;
 
    for(int i = 0;i < m;++i) s += 'R';
    for(int i = 1;i <= b;++i) {
        ans += s;
        if(i <= r % (b + 1)) {
            ans += 'R';
        }
        ans += 'B';
    }
    ans += s;
    cout << ans << "\n";
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