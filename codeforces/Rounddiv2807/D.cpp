#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if(s[0] != t[0] || s[n - 1] != t[n - 1]) {
        cout << "-1\n";
        return;
    }
    int a = 0, b = 0;
    vector<pair<int, int>> sa, ta;
    for(int i = 0;i < n;++i) {
        if(s[i] == '0') continue;
        int j = i;
        while(j < n && s[j] == '1') {
            j ++;
        }
        sa.push_back({i, j - 1});
        a ++;
        i = j - 1;
    }

    for(int i = 0;i < n;++i) {
        if(t[i] == '0') continue;
        int j = i;
        while(j < n && t[j] == '1') {
            j ++;
        }
        ta.push_back({i, j - 1});
        b ++;
        i = j - 1;
    }
    // cout << a << " " << b << "\n";
    if(a != b) {
        cout << "-1\n";
        return ;
    }
    long long ans = 0;
    for(int i = 0;i < sa.size();++i) {
        int l = min(sa[i].first, ta[i].first), r = max(sa[i].second, ta[i].second);
        ans += 2 * (r - l + 1) - (sa[i].second - sa[i].first + 1) - (ta[i].second - ta[i].first + 1);
    }
    cout << ans << '\n';
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