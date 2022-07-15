#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    bool judge(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
        ll a = (y1 - y2), b = (x1 - x2), c = y3 - y2, d = x3 - x2;
        if((a * d == b * c)) return true;
        return false;
    }
    int minimumLines(vector<vector<int>>& st) {
        int n = st.size();
        if(n == 1) return 0;
        vector<int> pos(n);
        for(int i = 0;i < n;++i) pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int a, int b) {
            return st[a][0] < st[b][0];
        });
        int ans = 1;
        for(int i = 2;i < n;++i) {
            if(judge(st[pos[i - 2]][0], st[pos[i - 2]][1], st[pos[i - 1]][0], st[pos[i - 1]][1], st[pos[i]][0], st[pos[i]][1])) {
                continue;
            }
            else {
                ans ++;
            }
        }
        return ans;
    }
};