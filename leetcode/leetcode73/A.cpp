#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;


template <typename T, typename W>
vector<int> KMP(T &p, T &s, W m, W n) {
    unordered_map<W, W> ne;
    vector<W> ans;
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> arr;
        for(int i = 0;i < n;i++) {
            mp[nums[i]] ++;
            if(i < n - 1 && nums[i] == key) arr.push_back(nums[i + 1]); 
        }
        int ans = 0, res = 0;
        for(int i = 0;i < arr.size();i++) {
            if(mp[arr[i]] > res) {
                res = mp[arr[i]];
                ans = arr[i];
            }
        }
        return ans;
    }
};

