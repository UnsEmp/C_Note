#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> nums(n);
        map<int, int> mp;
        vector<int> pos(n);
        for(int i = 0;i < n;++i) pos[i] = i;
        for(int i = 0;i < roads.size();++i) {
            nums[roads[i][0]] ++, nums[roads[i][1]] ++;
            mp[roads[i][0]] ++, mp[roads[i][1]] ++;
        }
        sort(pos.begin(), pos.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        long long sum = 0;
        int t = 1;
        for(int i = 0;i < n;++i) {
            sum += 1LL * t * nums[pos[i]];
            t ++;
        }
        return sum;

    }
};