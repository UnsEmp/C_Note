#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) {
            return 0;
        }
        vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = 1;
        int Max = INT_MIN;
        for(int i = 0;i < n + 1;i++) {
            if((2 * i) >= 2 && (2 * i) <= n) {
                nums[2 * i] = nums[i];
            }
            if((2 * i + 1) >= 2 && (2 * i + 1) <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
            Max = max(Max, nums[i]);
        }
        return Max;
    }
};