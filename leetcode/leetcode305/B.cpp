#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 1;
    map<int, bool> mp;
    map<int, vector<int>> grid;
    void dfs(int idx) {
        for(int i = 0;i < grid[idx].size();++i) {
            if(!mp[grid[idx][i]]) {
                ans ++;
                mp[grid[idx][i]] = true; 
                dfs(grid[idx][i]);
                // mp[grid[idx][i]] = false;
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        for(auto & r : restricted) mp[r] = true;
        for(auto & e: edges) grid[e[0]].push_back(e[1]), grid[e[1]].push_back(e[0]);
        mp[0] = true;
        dfs(0);
        return ans;
    }
};