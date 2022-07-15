#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> &nums, int x, int k) {
        for(int i = 0;i < nums.size();++i) {
            int t = max(0, nums[i] - x);
            if(k >= t) k-= t;
            else return false;
        }
        return true;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> nums;
        int l = 0, r = 0;
        for(int i = 0;i < nums1.size();++i) {
            int t = abs(nums1[i] - nums2[i]);
            r = max(r, t);
            nums.push_back(t);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int k = k1 + k2;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(nums, mid, k)) r = mid;
            else l = mid + 1;
        }
        for(int i = 0;i < nums.size();++i) {
            if(nums[i] > l) {
                k -= (nums[i] - l);
                nums[i] = l;
            }
        }
        for(int i = 0;i < nums.size();++i) {
            if(k) {
                if(nums[i] > 0) nums[i] --;
            }
            else {
                break;
            }
            k --;
        }
        long long ans = 0;
        for(int i = 0;i < nums.size();++i) {
            ans += (long long)nums[i] * nums[i];
        }
        return ans;
    }
};