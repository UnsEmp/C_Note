#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 10010 * 2;
int h[N], ne[M], w[M], ver[M], idx;
int dist[N][110], p[N];
bool st[N][110];
int n, m;

struct Node {
    int sum;
    int fuel;
    int pos;
};

bool operator < (const Node a, const Node b) {
    return a.sum > b.sum;
}

void init() {
    memset(h, 0, sizeof h);
    idx = 1;
}

void add(int x, int y, int z) {
    ver[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++; 
}

int dijkstra(int c, int s, int e) {
    if(s == e) return 0;
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s][0] = 0;
    priority_queue<Node> q;
    q.push({0, 0, s});
    int sum, fuel, pos;
    while(q.size()) {
        sum = q.top().sum, fuel = q.top().fuel, pos = q.top().pos;
        q.pop();
        if(st[pos][fuel]) continue;
        st[pos][fuel] = true;
        if(pos == e) {
            return sum;
        }
        if(fuel < c) q.push({sum + p[pos], fuel + 1, pos});
        for(int i = h[pos];i;i = ne[i]) {
            int y = ver[i], z = w[i];

            if(fuel >= z && sum <= dist[y][fuel - z]) {
                dist[y][fuel - z] = sum;
                if(y == e) {
                    return sum;
                }
                q.push({sum, fuel - z, y});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for(int i = 0;i < n;++i) cin >> p[i];
    for(int i = 0;i < m;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int q;
    cin >> q;
    while(q--) {
        int c, s, e;
        cin >> c >> s >> e;
        int t = dijkstra(c, s, e);
        if(t == -1) cout << "impossible\n";
        else cout << t << "\n";
    }
    return 0;
}



