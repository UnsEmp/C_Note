#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bo, int to, vector<int>& sp) {
        sort(sp.begin(), sp.end());
        int t = 0;
        int ans = 0, ne = bo;
        for(int i = 0;i < sp.size();++i) {
            // cout << ne << " " << sp[i] << "\n";
            ans = max(ans, sp[i] - ne);
            ne = sp[i] + 1;
        }
        ans = max(ans, to - sp[sp.size() - 1]);
        // for(int i = bo;i <= to;++i) {
        //     int j = i;
        //     while(t < sp.size() && j < to && j < sp[t]) {
        //         j ++;
        //     }
        //     ans = max(ans, j - i + 1);
        //     i = j;
        //     t ++;
        // }
        return ans;
    }
};