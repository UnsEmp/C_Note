#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;++i)
            if(s[i] == '0') ans ++;
        for(int i = n - 1;i >= 0;--i) {
            int num = s[i] - '0', cnt = 1;
            int j = i - 1, pos = 1;
            while(j >= 0) {
                if(s[j] == '1') {
                    // int t = (int)pow(2, pos);
                    if((pos <= 30) && num + (1 << pos) <= k) {
                        cnt ++;
                        num += (1 << pos);
                    }
                }
                else {
                    cnt ++;
                }
                pos ++;
                j --;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};