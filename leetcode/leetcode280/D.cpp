#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
class Solution {
public:
    bool st[20];
    int calnum(vector<int> & nums, int n, int m) {
        auto cmp = [](pii a, pii b) {
            return a.first < b.first;
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
        for(int i = 0;i < n;i++) {
            if(st[i]) continue;
            int w = 0;
            for(int j = 0;j < 4;j++) {
                if((nums[i] >> j) & 1) w += (j + 1);
            }
            q.push({w, i});
        }
        int ans = 0;
        for(int i = 0;q.size() && i < 2;i++) {
            auto [w, x] = q.top();
            q.pop();
            st[x] = true;
            ans += (nums[x] & m);
        }
        return ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size(), ans = 0;
        for(int i = numSlots;i >= 1;i--) {
            ans += calnum(nums, n, i);
        }
        return ans;
    }
};