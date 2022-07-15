#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    map<int ,int> mp;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        if(!mp[t]) a.push_back(t), mp[t]++;
        else if(mp[t] == 1) {
            b.push_back(t);
            mp[t] ++;
        }
    }
    int l = a.size(), r = b.size();
    cout << max(1, (l + r + 1) / 2) << "\n";
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