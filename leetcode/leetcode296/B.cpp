#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n;++i) {
            int j = i;
            while(j + 1 < n && nums[j + 1] - nums[i] <= k) j ++;
            ans ++;
            i = j;
        }
        return ans;
    }
};