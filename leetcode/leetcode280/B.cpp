#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> sign;
        int n = nums.size(), Max = 0, t = -1, m;
        m = n / 2;
        if(m % 2 == 1) m ++;
        for(int i = 0;i < n;i += 2) {
            mp[nums[i]] ++;
            if(mp[nums[i]] > Max) {
                Max = mp[nums[i]];
                t = nums[i];
            }
        }
        int Max1 = 0, t1 = -1;
        for(int i = 1;i < n;i += 2) {
            sign[nums[i]] ++;
            if(sign[nums[i]] > Max1) {
                Max1 = sign[nums[i]];
                t1 = nums[i];
            }
        }
        if(t1 == t) {
            return min(m - Max + Max1, Max + (n - m - Max1));
        }
        else {
            return n - Max - Max1;
        }
        // for(auto [a, b] : mp) {
        //     arr.push_back({a, b});
        // }
        // for(auto [a, b] : sign) {
        //     brr.push_back({a, b});
        // }
        // for(int i = arr.size() - 1;i >= 0;i --) {
        //     for(int j = brr.size() - 1;j >= 0;j --) {
        //         if(arr[i][0] != brr[j][0]) {
        //             ans = min(ans, n - (arr[i][1] + brr[j][1]));
        //         }
        //     }
        // }
    }
};