#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> dp(n);
        unordered_map<int, int> mp;
        int Max = -1;
        for(int i = 0;i < n;i++) {
            dp[i] = 1;
            mp[dp[i]]++;
        }
        for(int i = 0;i < n;i++) {
            int ans = 1;
            for(int j = i - 1;j >= 0;j--) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    ans = max(dp[j] + 1, ans);
                    mp[ans]++;
                }
            }
            dp[i] = ans;
            Max = max(Max, dp[i]);
        }
        // return dp[n - 1];
        // if(dp[n - 1] == 1) return nums.size();
        // for(int i = 0;i < n;i++) {
        //     cout << dp[i] << endl;
        // }
        // int count = 0;
        // // int tmp = dp[n - 1];
        // for(int i = 0;i < n;i++) {
        //     if(dp[i] == Max - 1) count++;
        // }
        return Max;
    }
};

int main() {
    Solution so;
    vector<int> arr = {1,2,4,3,5,4,7,2};
    cout << so.findNumberOfLIS(arr);
    return 0;
}