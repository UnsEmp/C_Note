#include <bits/stdc++.h>
using namespace std;

//原方法遍历
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int count = 0;
        for(int i = 1;i < n - 1;i++) {
            int diff = nums[i] - nums[i - 1];
            int temp = i;
            for(int j = i + 1;j < n;j++) {
                if(nums[j] - nums[temp] == diff) {
                    count++;
                    temp++;
                }
                else
                    break;
            }
        }
        return count;
    }
};

//difference and count
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int count = 0;
        int sum = 0;
        int diff = nums[0] - nums[1];
        for(int i = 2;i < n;i++) {
            if(nums[i - 1] - nums[i] == diff) {
                count++;
            }
            else {
                diff = nums[i - 1] - nums[i];
                count = 0;
            }
            sum += count;
            // int diff = nums[i] - nums[i - 1];
            // int temp = i;
            // for(int j = i + 1;j < n;j++) {
            //     if(nums[j] - nums[temp] == diff) {
            //         count++;
            //         temp++;
            //     }
            //     else
            //         break;
            // }
        }
        return sum;
    }
};