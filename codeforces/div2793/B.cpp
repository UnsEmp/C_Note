#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        if(t != i) {
            if(!cnt) {
                cnt ++;
                ans = t;
            }
            else {
                ans &= t;
            }
        }
    }
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