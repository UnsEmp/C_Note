#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    for(int i = 0;i < s.size();++i) {
        if((s[i] - '0') == 1) l = i;
        else if((s[i] - '0') == 0) {
            r = i;
            break;
        }
    }
    cout << (r - l + 1) << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    } 
    return 0;
}