#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> prifix;
    long long fun(int l, int r) {
        return prifix[r] - prifix[l - 1];
    }
    int waysToSplitArray(vector<int>& nums) {
        prifix.push_back(0);
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < nums.size();++i) prifix.push_back(prifix[i] + nums[i]);
        for(int i = 0;i < nums.size() - 1;++i) {
            if(fun(1, i + 1) >= fun(i + 2, n)) ans ++;
        }
        return ans ;
    }
};