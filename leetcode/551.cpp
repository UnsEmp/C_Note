#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int count = 0;
        bool flag = true;
        string ans = "LLL";
        for(int i = 0;i < s.size();i++) {
            if(s[i] == 'A')
                count++;
        }
        return ((s.find(ans) == string::npos) && (count < 2));
    }
};