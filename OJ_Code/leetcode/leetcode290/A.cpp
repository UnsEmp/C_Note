#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    int n, m;
    unordered_map<int, int> mp[1010];
    bool judge(vector<vector<int>>& nums, int x) {
        for(int i = 0;i < nums.size();++i) {
            bool flag = false;
            for(int j = 0;j < nums[i].size();++j) {
                if(nums[i][j] == x) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
    vector<int> intersection(vector<vector<int>>& nums) {
        n = nums.size(), m = nums[0].size();
        // for(int i = 0;i < n;++i) {
        //     for(int j = 0;j < m;++j) {
        //         mp[i][nums[i][j]] ++;
        //     }
        // } 
        set<int> ans;
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                if(judge(nums, nums[i][j])) ans.insert(nums[i][j]);
            }
        }
        // sort(ans.begin(), ans.end());
        vector<int> arr(ans.begin(), ans.end());
        return arr;
    }
};