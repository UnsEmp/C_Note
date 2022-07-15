#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> arr;
        for(int i = 0;i < capacity.size();++i) {
            arr.push_back(capacity[i] - rocks[i]);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0;i < arr.size();++i) {
            if(additionalRocks >= arr[i]) {
                ans ++;
                additionalRocks -= arr[i];
            }
            else break;
        }
        return ans;
    }
};