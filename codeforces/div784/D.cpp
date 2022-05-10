#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0, j = 0;i < n;++i) {
        // unordered_map<char, 
        int mp[128];
        memset(mp, 0, sizeof mp);
        while(j < n && (s[j] != 'W')) {
            mp[s[j]] ++;
            j ++;
        }
        if(!mp['B'] && !mp['R']) {
            i = j ++;
            continue;
        }
        int t = j - i;
        if(t == 1 || ((!mp['B'] || !mp['R']))) {
            cout << "NO" << "\n";
            return ;
        }
        i = j++;
    }
    cout << "YES" << "\n";
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