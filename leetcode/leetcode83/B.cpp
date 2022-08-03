#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i < nums.size();++i) {
            if(nums[i] == 0) {
                int j = i;
                while(j + 1 < nums.size() && nums[j + 1] == 0) {
                    j ++;
                }
                long long t = (j - i + 1);
                ans += (1 + t) * t / 2;
                i = j;
            }
        }
        return ans;
    }
};