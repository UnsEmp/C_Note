#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool judge(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int cnt = 0;
        for(int i = 0;i < s1.size() && i < s2.size();++i) {
            if(s1[i] == s2[i]) cnt ++;
            else break;
        }
        return cnt == s1.size();
    } 
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(int i = 0;i < words.size();++i) {
            if(judge(words[i], s)) ans ++;
        }
        return ans;
    }
};