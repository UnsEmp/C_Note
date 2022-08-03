#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 4e6 + 10;
int n, idx = 0;
vector<vector<int>> e(N), w(N);
vector<int> nums(N);
vector<int> mp(N);
int son[M][2];


void insert(int x) {
    int p = 0;
    for(int i = 30;i >= 0;--i) {
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, sum = 0;
    for(int i = 30;i >= 0;--i) {
        int u = (x >> i) & 1;
        if(son[p][!u]) p = son[p][!u], sum += (1 << i);
        else p = son[p][u];
    }
    return sum;
}


void dfs(int p, int sum) {
    for(int i = 0;i < e[p].size();++i) {
        int a = e[p][i], b = w[p][i];
        nums[a] = sum ^ b;
        if(!mp[a]) {
            mp[a] = 1;
            dfs(a, sum ^ b);
        }

    }
}

int main() {
    cin >> n;
    for(int i = 0;i < n - 1;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].emplace_back(b), w[a].emplace_back(c);
        e[b].emplace_back(a), w[b].emplace_back(c);
    }
    memset(son, 0, sizeof son);
    mp[0] = 1;
    dfs(0, 0);
    int ans = INT_MIN;
    for(int i = 0;i < n;++i) insert(nums[i]);
    for(int i = 0;i < n;++i) ans = max(ans, query(nums[i])); 
    cout << ans << "\n";
    return 0;
}