#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ans = 0;
    map<int, int> mp;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();++i) {
        if(!mp[s[i]]) {
            mp[s[i]] ++;
            ans += 2;
        }
        else {
            ans ++;
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