#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(vector<int> &ma, vector<vector<int>>& cookbooks, int t) {
        for(int i = 0;i < cookbooks[t].size();++i) {
            if(ma[i] < cookbooks[t][i]) return false;
        }
        return true;
    }
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int n = materials.size(), m = cookbooks.size(), ans = -1;
        for(int i = 1;i < (1 << m);++i) {
            vector<int> ma(materials.begin(), materials.end());
            int li = 0, v = 0;
            for(int j = 0;j < m;++j) {
                if(1 & (i >> j) && judge(ma, cookbooks, j)) {
                    li += attribute[j][1];
                    v += attribute[j][0];
                    for(int t = 0;t < materials.size();++t) {
                        ma[t] -= cookbooks[j][t];
                    } 
                }
            }
            if(li >= limit) ans = max(ans, v);
        }
        return ans;
    }
};