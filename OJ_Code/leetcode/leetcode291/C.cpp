#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    set<vector<int>> st;
    void dfs(int idx, int t, int k, int p, vector<int> & nums) {
        for(int i = 0;i < arr.size();++i) cout << arr[i] << " ";
        cout << "\n";
        if(arr.size() != 0)
        st.insert(arr);
        if(idx >= nums.size()) return ;
        if(t < k) {
            arr.push_back(nums[idx]);
            if(nums[idx] % p == 0) t ++;
            dfs(idx + 1, t, k, p, nums);
            if(nums[idx] % p == 0) t --;
            arr.pop_back();
        }
        else return ;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        for(int i = 0;i < nums.size();++i) {
            dfs(i, 0, k, p, nums);
        }
        // for(auto s : st) {
        //     for(auto i : s)  {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        return st.size();
    }
};