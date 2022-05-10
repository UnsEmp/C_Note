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

#define N 15
class Solution {
public:
    vector<int> v = vector<int>(N);
    vector<int> w = vector<int>(N);
    vector<int> maximumBobPoints(int num, vector<int>& al) {
        int n = al.size();
        vector<int> ans(n), arr(n);
        int Max = 0;
        for(int i = 1;i <= (1 << 12);++i) {
            int t = 0;
            for(int j = 0;j <= 11;++j) {
                if((i >> j) & 1) {
                    arr[j] = al[j] + 1;
                    t += j; 
                }
            }
            if(t > Max)  {
                Max = t;
                for(int k = 0;k <= 11;++k) ans[k] = arr[k];
            }
        }
        return ans;
    }
};