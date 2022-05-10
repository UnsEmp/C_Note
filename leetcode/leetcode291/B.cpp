#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
class Solution {
public:
    int mp[N];
    int minimumCardPickup(vector<int>& cards) {
        memset(mp, 0, sizeof mp);
        int ans = INT_MAX;
        for(int i = 0;i < cards.size();++i) {
            if(!mp[cards[i]]) {
                mp[cards[i]] = i + 1;
            }
            else {
                ans = min(ans, i - (mp[cards[i]] - 1) + 1);
                mp[cards[i]] = i + 1;
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};