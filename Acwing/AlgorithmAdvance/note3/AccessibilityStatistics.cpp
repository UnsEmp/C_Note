#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
int h[N], ne[N], ver[N], tot;
int v[N], deg[N];
int n, m;
vector<bitset<N>> arr(N);

void init() {
    memset(h, 0, sizeof h);
    memset(ne, 0, sizeof ne);
    memset(ver, 0, sizeof ver);
    memset(v, 0, sizeof v);
    tot = 1;
}

void add(int a, int b) {
    ver[tot] = b, ne[tot] = h[a], h[a] = tot++;
    deg[b] ++;
}

void TopSort(vector<int> & nums) {
    queue<int> q;
    for(int i = 1;i <= n;++i) {
        if(deg[i] == 0) q.push(i);
    }
    while(q.size()) {
        auto t = q.front();
        q.pop();
        nums.push_back(t);
        for(int i = h[t];i;i = ne[i]) {
            int y = ver[i];
            deg[y] --;
            if(deg[y] == 0) q.push(y);
        }
    }
}

void dfs(int x) {
    v[x] = 1;
    for(int i = h[x];i ;i = ne[i]) {
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
        arr[x] |= arr[y];
    }
}

int main() {
    init();
    cin >> n >> m;
    for(int i = 0;i < m;++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        arr[a].set(b);
    }

    vector<int> nums;
    TopSort(nums);
    for(int i = nums.size() - 1;i >= 0;--i) {
        int x = nums[i];
        for(int j = h[x];j;j = ne[j]) {
            int y = ver[j];
            arr[x] |= arr[y];
        }
    }

    for(int i = 1;i <= n;++i) {
        cout << arr[i].count() + 1 << "\n";
    }
    return 0;
}