#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, pair<int, int>> mp;
    map<int, int> sign;
    int t, l, r;
    for(int i = 0;i < n;++i) {
        // int t;
        cin >> t;
        if(!sign[t]) {
            mp[t] = make_pair(i, i);
            sign[t] ++;
        }
        else {
            mp[t].first = min(mp[t].first, i);
            mp[t].second = max(mp[t].second, i);
        }
    }
    while(m --) {
        int a, b;
        cin >> a >> b;
        if(sign[a] && sign[b] && mp[a].first <= mp[b].second) cout << "YES" << "\n";
        else cout << "NO" << "\n";
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