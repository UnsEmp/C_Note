#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        vector<int> up(128), lo(128);
        string ans;
        for(int i = 0;i < n;++i) {
            char u = s[i];
            if(s[i] >= 65 && s[i] <= 91) up[s[i]] ++;
            else lo[s[i]] ++;
            char t = s[i];
            if(s[i] >= 65 && s[i] <= 91) {
                t += 32;
                if(up[s[i]] && lo[t]) {
                    // ans += s[i];
                    if(ans == "") ans += s[i];
                    else ans[0] = max(ans[0], s[i]);
                }
            }
            else {
                t -= 32;
                if(up[t] && lo[s[i]]) {
                    // ans += t;
                    // return ans;
                    if(ans == "") ans += t;
                    else ans[0] = max(ans[0], t);
                }
            }
        }
        return ans;
    }
};