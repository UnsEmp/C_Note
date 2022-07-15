#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& ca) {
        int nums[40];
        memset(nums, 0 ,sizeof nums);
        int n = ca.size();
        for(int i = 0;i < n;++i) {
            int t = ca[i];
            for(int j = 0;j < 31;++j) {
                if((t >> j) & 1) nums[j] ++;
            }
        }
        int ans = 0;
        for(int i = 0;i < 31;++i) ans = max(ans, nums[i]);
        return ans;
    }
};