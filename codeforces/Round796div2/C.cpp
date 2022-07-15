#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<char, int> mp;
    string s;
    for(int i = 0;i < n * 2 + 1;++i) {
        cin >> s;
        for(auto &j : s) mp[j] ++;
    }
    for(auto &m : mp) {
        if(mp[m.first] % 2) {
            cout << m.first << "\n";
            break;
        }
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