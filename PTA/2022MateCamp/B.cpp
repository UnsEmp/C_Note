#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int h[N], ne[N], ver[N], idx;
int ai[N], bi[N];
bool st[N];

void init() {
    memset(h, 0, sizeof h);
    idx = 1;
}

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int x) {
    
}


void solve() {
    cin >> n;
    for(int i = 0;i < n;++i) cin >> ai[i];
    for(int i = 0;i < n;++i) cin >> bi[i];
    memset(st, 0, sizeof st);
    for(int i = 0;i < n;++i) {
        add(bi[i], i + 1);
    }
    for(int i = 1;i <= n;++i) {
        if(!dfs(i)) {
            cout << "-1\n";
        }
    }
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        solve();
    }
    return 0;
}