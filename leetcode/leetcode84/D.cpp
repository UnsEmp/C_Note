#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    bool check(ll mid, ll x, ll y) {
        return (x / mid + (x % mid != 0)) <= y;
    }
    long long minimumReplacement(vector<int>& nums) {
        ll n = nums.size();
        if(n == 1) return 0;
        ll ans = 0;
        for(int i = n - 2;i >= 0;--i) {
            int j = i;
            while(j >= 0 && nums[j] <= nums[j + 1]) {
                -- j;
            }
            int l, r;
            if(j >= 0) {
                l = 1, r = nums[j];
                while(l < r) {
                    int mid = (l + r) >> 1;
                    if(check(mid, nums[j], nums[j + 1])) r = mid;
                    else l = mid + 1;
                }
                ans += l - 1;
                nums[j] = nums[j] / l;
            }
            i = j;
        }
        return ans;
    }
};