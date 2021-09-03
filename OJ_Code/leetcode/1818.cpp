#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.begin(), nums1.end());
        sort(ans.begin(), ans.end());
        int Max = 0;
        int sum = 0;
        for(int i = 0;i < nums1.size();i++){
            int temp = abs(nums1[i] - nums2[i]);
            sum = (temp + sum) % 1000000007;
            int j = lower_bound(ans.begin(), ans.end(), nums2[i]) - ans.begin();
            if(j < ans.size()){
                int a = temp - (ans[j] - nums2[i]);
                Max = max(Max, a);
            }
            if(j > 0){
                int a = temp - (nums2[i] - ans[j-1]);
                Max = max(Max, a);
            }
        }
        return (sum - Max + 1000000007) % 1000000007;
    }
};