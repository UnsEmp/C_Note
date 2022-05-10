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
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        long long n = nums1.size();
        long long ans = (n - 2) * (n + 1 - 2) / 2;
        for(int i = 0;i < nums1.size();i++) m1[nums1[i]] = i;
        // for(int i = 0;i < nums2.size();i++) m2[nums2[i]] = i;
        for(int i = 0;i < n;i++) {
            if(nums1[i] == nums2[i]) continue;
            else {
                ans -= (abs(i - m1[nums2[i]]));
                i = max(i, m1[nums2[i]]);
            }
        }
        return ans;
    }
};




