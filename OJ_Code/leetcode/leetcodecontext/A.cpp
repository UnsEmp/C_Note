#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(int i = 0;i < operations.size();++i) {
            gem[operations[i][1]] += gem[operations[i][0]] / 2;
            gem[operations[i][0]] -= gem[operations[i][0]] / 2;
        }
        sort(gem.begin(), gem.end());
        int n = gem.size();
        return gem[n - 1] - gem[0];
    }
};