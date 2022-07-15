#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        while(nums.size() > 1) {
            int n = nums.size();
            vector<int> arr(n / 2);
            for(int i = 0;i < n / 2;++i) {
                if(i % 2 == 0) arr[i] = min(nums[2 * i], nums[2 * i + 1]);
                else arr[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = arr;
        } 
        return nums[0];
    }
};