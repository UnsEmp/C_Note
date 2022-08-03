#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 0;
        int mp[k + 1];
        for(int i = 0;i < rolls.size();++i) {
            int j = i, cnt = 0;
            memset(mp, 0, sizeof mp);
            while(j < rolls.size() && cnt < k) {
                if(!mp[rolls[j]]) {
                    mp[rolls[j]] ++;
                    cnt ++;
                }
                j ++;
            }
            if(cnt == k) {
                ans ++;
            }
            i = j - 1;
        }
        return ans + 1;
    }
};