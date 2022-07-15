#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    // int cnt = 0;
    int ans = 0;
    for(int i = 0;i < s.size();++i) {
        // if(!mp[s[i]]) {
        //     mp[s[i]] ++;
        //     cnt ++;
        // }
        int j = i;
        map<char, int> mp;
        int cnt = 0;
        while(j < s.size()) {
            if(!mp[s[j]]) {
                mp[s[j]] ++;
                cnt ++;
                if(cnt > 3) break;
            }
            j ++;
        }
        // cout << j << " ";
        ans ++;
        i = j - 1;
    }
    // int ans = cnt / 3;
    // cout << cnt << "\n";
    // if(cnt % 3 != 0) ans ++;
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