#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), m = nums.size();
        vector<int> ans(n);
        vector<int> pos(m);
        // iota(pos.begin(), pos.end(), 0);
        for(int i = 0;i < n;++i) {
            int k = queries[i][0], t = queries[i][1];
            iota(pos.begin(), pos.end(), 0);
            sort(pos.begin(), pos.end(), [&](int a, int b) {
                // string s1 = nums[a].substr(nums[a].size() - t, t), s2 = nums[b].substr(nums[b].size() - t, t);
                // // return s1 < s2;
                for(int j = nums[a].size() - t;j < nums[a].size();++j) {
                    if(nums[a][j] != nums[b][j]) return nums[a][j] < nums[b][j];
                }
                return a < b;
            });
            ans[i] = pos[k - 1];
        }
        return ans;
    }
};