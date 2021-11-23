#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> arr;
    unordered_map<int, bool> mp;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        dfs(nums, ans, 0);
        return arr;
    }
    void dfs(vector<int> & nums, vector<int> ans, int index) {
        if(index == nums.size()) {
            arr.push_back(ans);
            return ;
        }

        for(int i = 0;i < nums.size();i++) {
            if(!mp[i]) {
                ans.push_back(nums[i]);
                mp[i] = true;
                dfs(nums, ans, index + 1);
                mp[i] = false;
                ans.erase(ans.end() - 1);
            }
        }
    }
};

int main() {
    Solution in;
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    ans = in.permute(arr);
    for(int i = 0;i < ans.size();i++) {
        for(int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}