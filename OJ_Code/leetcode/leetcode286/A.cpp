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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<set<int>> ans(2);
        vector<vector<int>> arr;
        unordered_map<int, int> n1, n2;
        for(auto n : nums1) n1[n] ++;
        for(auto n : nums2) n2[n] ++;
        for(auto n : nums1) {
            if(!n2[n]) ans[0].insert(n);
        }
        for(auto n : nums2) {
            if(!n1[n]) ans[1].insert(n);
        }
        arr.emplace_back(ans[0].begin(), ans[0].end());
        arr.emplace_back(ans[1].begin(), ans[1].end());
        return arr;
    }
};