#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto & i: nums) q.push(i);
        int ans = 0, res = 0;
        while(q.size()) {
            auto t = q.top();
            q.pop();
            if(t - res > 0) {
                res += t - res;
                ans ++;
            }

        }
        return ans;
    }
};