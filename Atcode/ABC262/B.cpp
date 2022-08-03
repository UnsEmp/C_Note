#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    map<int, set<int>> mp;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;++i) {
        int u, v;
        cin >> u >> v;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    int ans = 0;
    for(int i = 1;i <= n;++i) {
        for(int j = i + 1;j <= n;++j) {
            for(int k = j + 1;k <= n;++k) {
                if(mp[i].find(j) != mp[i].end() && mp[j].find(k) != mp[j].end() && mp[k].find(i) != mp[k].end()) {
                    ans ++;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int _;
    // cin >> _;
    // while(_--) {
        solve();
    // }
    return 0;
}