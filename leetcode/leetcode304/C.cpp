#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], ne[N], ver[N], idx;

struct Node {
    int sum;
    int x;
};

bool operator<(const Node a,  const Node b) {
    return a.sum > b.sum;
}

inline void init() {
    memset(h, 0, sizeof h);
    memset(ne, 0, sizeof ne);
    idx = 1;
}

inline void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

inline void dijkstra(int n ,int x, int dist[]) {
    dist[x] = 0;
    priority_queue<Node> q;
    q.push({0, x});
    bool st[N];
    memset(st, 0 ,sizeof st);
    while(q.size()) {
        auto [sum, x] = q.top();
        q.pop();
        if(st[x]) continue;
        st[x] = true;
        for(int i = h[x];i;i = ne[i]) {
            int y = ver[i];
            if(dist[x] + 1 < dist[y]) {
                dist[y] = dist[x] + 1;
                q.push({dist[y], y});
            }
        }
    }
}

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        init();
        int dist1[N], dist2[N];
        memset(dist1, 0x3f, sizeof dist1);
        memset(dist2, 0x3f, sizeof dist2);
        for(int i = 0;i < edges.size();++i) {
            if(edges[i] == -1) continue;
            add(i + 1, edges[i] + 1);
        }
        dijkstra(edges.size() ,node1 + 1, dist1), dijkstra(edges.size() ,node2 + 1, dist2);
        int res = 0x3f3f3f3f, ans;
        for(int i = 1;i <= edges.size();++i) {
            int t = max(dist1[i], dist2[i]);
            if(res > t) {
                res = t;
                ans = i;
            }
        }
        if(res == 0x3f3f3f3f) return -1;
        return ans - 1;
    }
};