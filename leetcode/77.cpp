#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> arr;
    unordered_map<int, int> mp;
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        dfs(n, k, 1, ans);
        return arr;
    }
    void dfs(int n, int k, int index, vector<int> ans) {
        if(ans.size() == k) {
            arr.push_back(ans);
            return ;
        }
        for(int i = index;i <= n;i++) {
            // if(!mp[index]) {
                ans.push_back(i);
                // mp[i]++;
                dfs(n, k, i + 1, ans);
                // mp[i]++;
                ans.erase(ans.end() - 1);
                // mp[i]--;
                // dfs(n, k, index + 1, ans);
            // }
        }

    }

};

int main() {
    int n, k;
    vector<vector<int>> arr;
    cin >> n >> k;
    Solution so;
    arr = so.combine(n, k);
    for(int i = 0;i < arr.size();i++) {
        for(int j = 0;j < arr[i].size();j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}