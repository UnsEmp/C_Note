#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        memset(dp, 0, sizeof dp);
        dp[0] = true, dp[1] = false;
        int n = nums.size();
        for(int i = 2;i <= n;++i) {
            if(nums[i - 1] == nums[i - 2] && dp[i - 2]) {
                dp[i] = true;
            }
            else if(i >= 3 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3] && dp[i - 3]) {
                dp[i] = true;
            }
            else if(i >= 3 && nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1 && dp[i - 3]) {
                dp[i] = true;
            }
        }
        return dp[n];
    }
};