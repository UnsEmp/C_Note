#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> r,s;
        for(int i = 0;i < 5;++i) {
            r[ranks[i]] ++;
            s[suits[i]] ++;
        }
        int ans = 0, cnt = 0;
        for(auto &[x, y] : s) {
            ans = max(ans, y);
        }
        for(auto& [x, y] : r) {
            cnt = max(cnt, y);
        }
        if(ans == 5) {
            return "Flush";
        }
        else if(cnt >= 3){
            return "Three of a Kind";
        }
        else if( cnt >= 2) {
            return "Pair";
        }
        return "High Card";

    }
};
