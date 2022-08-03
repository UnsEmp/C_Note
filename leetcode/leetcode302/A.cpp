#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans(2);
        map<int, int> mp;
        for(auto &i : nums) mp[i] ++;
        for(auto &[x, y] : mp) {
            ans[0] += (y / 2);
            ans[1] += y % 2;
        }      
        return ans;
    }
};