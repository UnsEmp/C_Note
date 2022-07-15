#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // int n = s.size();
    int i, j;
    i = j = s.size() / 2;
    while(i - 1 >= 0 && s[i] == s[i - 1]) i--;
    while(j + 1 < n && s[j] == s[j + 1]) j ++;
    int len = (j - i + 1);
    cout << len << "\n";
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