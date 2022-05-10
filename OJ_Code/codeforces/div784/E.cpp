#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 60, M = 60;
// int n, m;
vector<vector<char>> g(N, vector<char>(M));
ll n;
ll mp1[26][26], mp2[26][26];

void solve() {
    // int n, m;
    ll ans = 0;
    cin >> n;
    memset(mp1, 0, sizeof mp1);
    memset(mp2, 0, sizeof mp2);
    for(int i = 0;i < n;++i) {
        string s;
        cin >> s;
        for(char j = 'a';j <= 'k';++j) {
            if(j == s[1]) continue;
            else ans += mp1[s[0] - 'a'][j - 'a'];
        }
        for(char j = 'a';j <= 'k';++j) {
            if(j == s[0]) continue;
            else ans += mp2[s[1] - 'a'][j - 'a'];
        }
        mp1[s[0] - 'a'][s[1] - 'a'] ++;
        mp2[s[1] - 'a'][s[0] - 'a'] ++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}