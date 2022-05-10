#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<ll> f(n + 1);
        vector<ll> pos(26 + 1, -1);
        for(int i = 1;i <= n;++i) {
            if(pos[s[i - 1] - 'a'] != -1) f[i] = f[i - 1] + (i - pos[s[i - 1] - 'a']);
            else f[i] = f[i - 1] + i;
            pos[s[i - 1] - 'a'] = i; 
        } 
        ll ans = 0;
        for(int i = 1;i <= n;++i) ans += f[i];
        return ans;
    }
};