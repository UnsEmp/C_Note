#include <bits/stdc++.h>
using namespace std;
typedef long long int;
const int N = 1e5 + 10;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<set<int>> ans(2);
        int in[N], out[N];
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        int len = 0;
        for(int i = 0;i < matches.size();++i) {
            out[matches[i][0]] ++;
            in[matches[i][1]] ++;
            len = max(len, max(matches[i][0], matches[i][1]));
        }
        for(int i = 1; i <= len;++i) {
            if(in[i] == 0 && out[i] > 0) ans[0].insert(i);
            if(in[i] == 1) ans[1].insert(i);
        }
        vector<vector<int>> res(2);
        res[0] = {ans[0].begin(), ans[0].end()};
        res[1] = {ans[1].begin(), ans[1].end()};
        return res;
    }
};