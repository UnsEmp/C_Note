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
    long long maximumSubsequenceCount(string text, string pattern) {
        unordered_map<char, long long> mp, mp1;
        long long st = 0, en = 0;
        int n = text.size();
        for(int i = 0;i < n;++i) {
            mp[text[i]] ++;
            if(text[i] == pattern[1]) {
                st += mp[pattern[0]];
                // cout << st << "\n";
            }
        }
        for(int i = n - 1;i >= 0;--i) {
            mp1[text[i]] ++;
            if(text[i] == pattern[0]) {
                en += mp1[pattern[1]];
                // cout << en << "\n";
            }
        }
        if(pattern[0] == pattern[1]) return (n - 1) * n / 2 + mp[pattern[0]];
        return max(mp[pattern[1]] + st, mp1[pattern[0]] + en);
    }
};