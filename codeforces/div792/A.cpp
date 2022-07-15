#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if(s.size() == 1) {
        cout << s << "\n";
        return ;
    }
    else if(s.size() == 2) {
        cout << s[1] << "\n";
        return ;
    }
    else {
        sort(s.begin(), s.end());
        cout << s[0] << "\n";
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