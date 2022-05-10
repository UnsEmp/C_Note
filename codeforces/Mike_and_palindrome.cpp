#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

void solve() {
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    bool flag = false;
    while(l < r) {
        if(s[l++] != s[r--]) {
            if(flag) {
                cout << "NO" << "\n";
                return ;
            }
            flag = true;
        }
    }
    if(flag || s.size() & 1)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main() {
    solve();
    return 0;
}
