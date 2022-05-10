#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = -1;
    cin >> n;
    // vector<int> arr(n);
    unordered_map<int, int> mp;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        mp[t] ++;
        if(mp[t] >= 3) ans = t;
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