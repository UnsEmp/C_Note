#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        int ans = -1;
        for(int i = 0;i < nums.size();++i) {
            string s = to_string(nums[i]);
            int sum = 0;
            for(int j = 0;j < s.size();++j) sum += s[j] - '0';

            if(!mp[sum]) {
                mp[sum] = i + 1;
            }
            else {
                int t = nums[i] + nums[mp[sum] - 1];
                if(t > ans) ans = t;
                mp[sum] = i + 1;
            }
        }
        return ans;
        // vector<vector<int>> arr(11);
        // for(int i = 0;i < nums.size();++i) {
        //     string s = to_string(nums[i]);
        //     int sum = 0;
        //     for(int j = 0;j < s.size();++j) sum += s[i] - '0';
        //     arr[sum].push_back(sum);
        // }
    }
};