#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string st, string ta) {
        string s, t;
        vector<int> pos, pot;
        for(int i = 0;i < st.size();++i) {
            if(st[i] != '_') {
                s += st[i];
                pos.push_back(i);
            }
        }
        for(int i = 0;i < ta.size();++i) {
            if(ta[i] != '_') {
                t += ta[i];
                pot.push_back(i);
            }
        }
        if(s != t) return false;
        int len = s.size();
        for(int i = 0;i < len;++i) {
            if(s[i] == 'L') {
                if(pos[i] < pot[i]) return false;
            }
            else {
                if(pos[i] > pot[i]) return false;
            }
        }
        return true;
    }
};