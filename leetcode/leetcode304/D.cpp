#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], ne[N], ver[N], idx;
int deg[N];
bool st[N];

inline void init() {
    memset(h, 0, sizeof h);
    memset(deg, 0, sizeof deg);
    idx = 1;
}

inline void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx++;
}



int dfs(int x) {
    if(st[x]) return 1;
    st[x] = 1;
    int sum = 1;
    for(int i = h[x];i;i = ne[i]) {
        int y = ver[i];
        if(!st[y]) sum = sum + dfs(y);
    }
    return sum;
}

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        init();
        memset(st, 0, sizeof st);
        memset(deg, 0,sizeof deg);
        int n = edges.size();
        for(int i = 0;i < edges.size();++i) {
            if(edges[i] == -1) continue;
            deg[edges[i] + 1] ++;
            add(i + 1, edges[i] + 1);
        }
        queue<int> q;
        for(int i = 1;i <= n;++i) {
            if(deg[i] == 0) q.push(i), st[i] = true;
        }
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int i = h[t];i;i=ne[i]) {
                int y = ver[i];
                deg[y] --;
                if(deg[y] == 0) q.push(y), st[y] = true;
            }
        }     
        int ans = -1;
        for(int i = 1;i <= n;++i) {
            if(st[i]) continue;
            
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};