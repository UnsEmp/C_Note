#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int i = 0;i < numsDivide.size();++i) {
            g = gcd(g, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();++i)
            if(g % nums[i] == 0) return i;
        return -1;
    }
};