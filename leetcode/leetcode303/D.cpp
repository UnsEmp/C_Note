#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        map<int, int> f;
        map<int, vector<int>> g;
        set<int> st;
        for(auto &nu : nums) st.insert(nu);
        for(auto& s : st) {
            int cnt = 0;
            for(int j = 0;j <= 30;++j) {
                if((s >> j) & 1) cnt ++;
            }
            f[s] = cnt;
            g[cnt].push_back(s);
        }
        long long ans = 0;
        for(int i = 0;i <= 30;++i) {
            for(int j = 0;j <= 30;++j) {
                if(i + j >= k)
                ans += (long long)g[i].size() * g[j].size();
            }
        }
        return ans;

    }
};