#include <bits/stdc++.h>
using namespace std;

//DFS
class Solution {
public:
    vector<vector<int>> arr;
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for(int i = 0;i < graph.size();i++) {
            for(int j = 0;j < graph[i].ize();j++) {
                mp[i].push_back(graph[i][j]);
            }
        }
        int n = graph.size();
        vector<int> ans;
        ans.push_back(0);
        dfs(0, n, ans);
        return arr;
    }
    void dfs(int index, int n, vector<int> & ans) {
        if(index == n - 1) {
            arr.push_back(ans);
            return ;
        }
        for(int i = 0;i < mp[index].size();i++) {
            ans.push_back(mp[index][i]);
            dfs(mp[index][i], n, ans);
            ans.erase(ans.end() - 1); 
        }
    }
};

/*
queue<int> q;
unordered_map<int, int> sign;
q.push(0);
int step = 0;
while(!q.empty()) {
    int len = q.size();
    vector<int> ans;
    for(int i = 0;i < len;i++) {
        int tmp = q.front();
        q.pop();
        for(int j = 0;j < mp[tmp].size();j++) {
            if(mp[tmp][j] > tmp) {
                q.push(mp[tmp][j]);
                ans.push_back(mp[tmp][j]);
            }
        }
    }
    arr.push_back(ans);
    step++;
} */