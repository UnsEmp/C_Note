#include <bits/stdc++.h>
using namespace std;
const int N = 20;
bool st[N], back[N];
bool dfs(int sum, int x) {
    if(sum == x) {
        for(int i = 1;i <= 9;++i) {
            back[i] = st[i];
        }
        return true;
    }
    for(int i = 9;i >= 1;--i) {
        if(!st[i]) {
            st[i] = true;
            if(dfs(sum + i, x)) return true;
            st[i] = false;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    memset(st, 0, sizeof st);
    memset(back, 0, sizeof back);
    dfs(0, n);
    string s;
    for(int i = 1;i <= 9;++i) {
        if(back[i]) s += i + '0';
    }
    cout << s << "\n";
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