#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    vector<ll> prifix;
    ll fun(int l, int r) {
        return prifix[r] - prifix[l - 1];
    }
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        prifix.push_back(0);
        int n = nums.size();
        for(int i = 0;i < n;++i) {
            prifix.push_back(nums[i] + prifix[i]);
        }
        int ans = 0, num = abs(fun(1, 1) - fun(2, n) / (n - 1));
        for(int i = 1;i < n;++i) {
            ll l = 0, r = 0;
            l = fun(1, i + 1) / (i + 1), r = fun(i + 1, n) / (n - (i));
            int t = abs(l - r);
            if(t < num) {
                ans = i;
                num = t;
            } 
        }
        return ans;
    }
};