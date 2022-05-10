#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define INF 0x3f3f3f3f
class Solution {
public:
    const int N = 1e5 + 10;
    void dijkstra(int str, vector<long long> & dis, int n, map<int, vector<pair<int, int>>> & edge) {
        dis[str] = 0;
        unordered_map<int, int> mp;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        mp[str] ++;
        for(int i = 0;i < edge[str].size();++i) {
            auto [v, w] = edge[str][i];
            if(dis[v] > dis[str] + w) {
                dis[v] = dis[str] + w;
            }
                q.push({w, v});
        }
        while(q.size()) {
            auto [w, v] = q.top();
            // cout << v << endl;
            q.pop();
            if(mp[v]) continue;
            else mp[v] ++;
            for(int i = 0;i < edge[v].size();++i) {
                auto [v1, w1] = edge[v][i];
                if(dis[v1] > dis[v] + w1) {
                    dis[v1] = dis[v] + w1;
                }
                q.push({w1, v1});
            } 
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<long long> dis1(N, INF), dis2(N, INF), dis3(N, INF);
        map<int, vector<pair<int, int>>> edge, edge1;
        for(auto a : edges) {
            edge[a[0]].emplace_back(a[1], a[2]);
            edge1[a[1]].emplace_back(a[0], a[2]);
        }
        dijkstra(src1, dis1, n, edge);
        dijkstra(src2, dis2, n, edge);
        dijkstra(dest, dis3, n, edge1);
        long long ans = INF;
        for(int i = 0;i < n;++i) {
            ans = min(ans, dis1[i] + dis2[i] + dis3[i]);
        }
        if(ans > INF / 2) return -1;
        else return ans;   
    }
};




[{
	"resource": "/d:/visual_stdio_code/leetcode/2203.cpp",
	"owner": "cpptools",
	"severity": 4,
	"message": "structured bindings only available with -std=c++17 or -std=gnu++17",
	"source": "gcc",
	"startLineNumber": 17,
	"startColumn": 18,
	"endLineNumber": 17,
	"endColumn": 18
}]