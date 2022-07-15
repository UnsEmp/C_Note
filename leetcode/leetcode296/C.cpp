#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> num, idx;
        int n = nums.size();
        for(int i = 0;i < n;++i) {
            idx[i] = nums[i];
            num[nums[i]] = i;
        }
        for(int i = 0;i < operations.size();++i) {
            int a = operations[i][0], b = operations[i][1];
            idx[num[a]] = b;
            num[b] = num[a];
        }
        vector<int> ans;
        for(int i = 0;i < n;++i) ans.push_back(idx[i]);
        return ans;
    }
};