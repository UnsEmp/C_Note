#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string res = to_string(num);
        int n = res.size();
        int ans = 0;
        for(int i = 0;i < n;++i) {
            string s = "";
            for(int j = i;j <= i + k - 1 && i + k - 1 < n;++j) {
                s += res[j];
            }
            int t = 0;
            if(s.size()) t = stoi(s);
            if(t && num % t == 0) {
                ans ++;
            }
        }
        return ans;
    }
};