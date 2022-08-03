#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 3e5 + 10;
int h[N], ne[M], ver[M], en[M], ph[M], idx;
int n, m;
int distEn[N], distPh[N];
// bool st[N];
struct Node {
    int e;
    int p;
    int pos;
};


bool operator<(const Node a, const Node b) {
    if(a.e != b.e) return a.e > b.e;
    return a.p < b.p;
}

void init() {
    memset(h, 0, sizeof h);
    memset(ne, 0, sizeof ne);
    idx = 1;
}

void add(int a, int b, int e, int p) {
    ver[idx] = b, en[idx] = e, ph[idx] = p, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    memset(distEn, 0x3f, sizeof distEn);
    memset(distPh, 0, sizeof distPh);
    // memset(st, 0, sizeof st);
    distEn[1] = 0;
    priority_queue<Node> q;
    // st[1] = true;
    q.push({0, 0, 1});
    while(q.size()) {
        auto [eSum, pSum, x] = q.top();
        q.pop();
        // if(eSum > distEn[x] || pSum < distEn) 
        // if(st[x]) continue;
        // st[x] = true;
        for(int i = h[x];i;i = ne[i]) {
            int y = ver[i], e = en[i], p = ph[i];
            // cout << x << " " << y << "\n";
            if(eSum + e <= distEn[y]) {
                distEn[y] = min(distEn[y], eSum + e);
                distPh[y] = max(distPh[y], pSum + p); 
                q.push({eSum + e, pSum + p, y});
            }
            // else if(distEn[x] + e == distEn[y] && pSum + p > distPh[y]) {
            //     distPh[y] = pSum + p;
            //     q.push({distEn[y], distPh[y], y}); 
            // }
        }
    }
}

void solve() {
    init();
    cin >> n >> m;
    for(int i = 0;i < m;++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
    }
    // for(int i = 1;i <= n;++i) {
    //     cout << i << "\n";
    //     for(int j = h[i];j;j = ne[j]) {
    //         cout << ver[j] << " ";
    //     }
    //     cout << "\n";
    // } 
    
    dijkstra();
    cout << distEn[n] << " " << distPh[n] << "\n";
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