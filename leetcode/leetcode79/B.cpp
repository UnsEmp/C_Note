#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(string s) {
        int sum = 0;
        int n = s.size();
        for(int i = 0;i < n;++i) {
            int j = i;
            while(j < n && s[j] != ' ') j ++;
            while(j < n && s[j] == ' ') j ++;
            // cout << i << " " << j << "\n";
            sum ++;
            i = j - 1;
        }
        return sum;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        for(int i = 0;i < senders.size();++i) {
            // cout << cal(messages[i]) << "\n";
            mp[senders[i]] += cal(messages[i]);
        }
        int ans = 0;
        string res;
        for(auto & m : mp) {
            if(m.second > ans) {
                ans = m.second;
                res = m.first;
            }
            else if(m.second == ans) {
                if(m.first > res) {
                    ans = m.second;
                    res = m.first;
                }
            }
        } 
        return res;
    }
};