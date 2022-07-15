#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> mp[9];
    vector<string> arr;
    string s;
    for(int i = 0;i < n;++i) {
        cin >> s;
        arr.push_back(s);
        mp[s.size()][s] = 1;
    } 
    vector<int> ans(n);
    for(int i = 0;i < n;++i) {
        bool flag = false;
        for(int j = 0;j < arr[i].size();++j) {
            string a = arr[i].substr(0, j + 1), b = arr[i].substr(j + 1, arr[i].size() - (j + 1));
            if(mp[a.size()][a] && mp[b.size()][b]) flag = true;
        }
        if(flag) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i = 0;i < n;++i) cout << ans[i];
    cout << "\n";
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