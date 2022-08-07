#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        map<ll, ll> mp;
        ll ans = 0;
        for(int i = 0;i < n;++i) {
            ll t = i;
            t -= mp[i - nums[i]];
            ans += t;
            mp[i - nums[i]] ++;
        }
        return ans;
    }
};