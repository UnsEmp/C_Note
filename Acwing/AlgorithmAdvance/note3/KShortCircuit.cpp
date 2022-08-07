#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int N = 1010, M = 2e4 + 10;
int h[N], rh[N], ver[M], w[M], ne[M], idx;
int n, m, s, t, k;
int dist[N], f[N];
int mp[N];

void init() {
    memset(h, 0, sizeof h);
    memset(rh, 0, sizeof rh);
    memset(ne, 0, sizeof ne);
    idx = 1;
}

void add(int *h ,int a, int b, int c) {
    ver[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int st, int en) {
    memset(mp, 0, sizeof mp);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    heap.push({0, st});
    while(heap.size()) {
        auto [dis, x] = heap.top();
        heap.pop();
        if(mp[x]) continue;
        mp[x] = 1;
        for(int i = rh[x];i;i = ne[i]) {
            int y = ver[i], l = w[i];
            if(dist[x] + l < dist[y]) {
                dist[y] = dist[x] + l;
                heap.push({dist[y], y});
            }
        }
    }
}

int a_star(int S, int T, int K) {
    memset(mp, 0, sizeof mp);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push({dist[S], {0, S}});
    while(q.size()) {
        auto [dis, x] = q.top().second;
        q.pop();
        mp[x] ++;
        if(mp[T] == k) {
            return dis;
        }
        for(int i = h[x];i;i = ne[i]) {
            int y = ver[i], l = w[i];
            if(mp[y] < k) {
                q.push({dis + l + dist[y], {dis + l, y}});
            } 
        }
    }
    return -1;
}

int main() {

    init();
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    for(int i = 0;i < m;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin >> s >> t >> k;
    if(s == t) k ++;
    dijkstra(t, s);
    cout << a_star(s, t, k) << "\n";
    return 0;
}

