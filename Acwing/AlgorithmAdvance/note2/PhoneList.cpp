#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 1e5 + 10;
int tr[N][10], cnt[N], idx;

inline void init() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
}

inline void insert(string &s) {
    int p = 0;
    for(int i = 0;i < s.size();++i) {
        int u = s[i] - '0';
        if(!tr[p][u]) {
            tr[p][u] = ++idx;
        }
        p = tr[p][u];
    }
    // cout << p << "\n";
    cnt[p] ++;
}

inline bool query(string &s) {
    int p = 0;
    for(int i = 0;i < s.size();++i) {
        int u = s[i] - '0';
        if(cnt[p]) {
            return true;
        }
        p = tr[p][u];
    }
    if(cnt[p] > 1) return true;
    return false;
}

void solve() {
    init();
    int n;
    cin >> n;
    string s;
    vector<string> arr;
    bool flag = true;
    for(int i = 0;i < n;++i) {
        cin >> s;
        arr.push_back(s);
        insert(s);
    }
    for(int i = 0;i < n;++i) {
        if(query(arr[i])) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}