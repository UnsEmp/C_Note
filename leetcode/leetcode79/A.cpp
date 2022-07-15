#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int a[10], cnt[10];
        memset(a, 0, sizeof a);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0;i < n;++i) {
            // cout << num[i] - '0' << "\n";a
            int t = num[i] - '0';
            a[i] = t;
            cnt[t] ++;
        } 
        for(int i = 0;i < 10;++i) {
            if(cnt[i] != a[i]) return false;
        }
        return true;

    }
};