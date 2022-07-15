#pragma message( "Compiling " __FILE__ ) 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(vector<int> &nums1, vector<int>&nums2) {
        int n = nums1.size();
        int ans = 0, add = 0;

        for(int i = 0;i < n;++i) {
            if(nums1[i] <= nums2[i]) {
                int j = i;
                int cnt = 0;
                while(j < n && cnt >= 0) {
                    cnt += (nums2[j] - nums1[j]);
                    add = max(add, cnt);
                    j ++;
                }
                i = j - 1;
            }
        }
        for(int i = 0;i < n;++i) ans += nums1[i];
        return ans + add;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(fun(nums1, nums2), fun(nums2, nums1));
    }
};

int main() {
    return 0;
}