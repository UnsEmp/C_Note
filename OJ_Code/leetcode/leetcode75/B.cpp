#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for(int i = 0;i < n;++i) f[1][i + 1] = nums[i];
        for(int i = 2;i <= n;++i) {
            for(int j = n - i + 1;j >= 1;j--) {
                f[i][j] = f[i - 1][j] + f[i - 1][j + 1];
            }
        }
        return f[n][1];
    }
};