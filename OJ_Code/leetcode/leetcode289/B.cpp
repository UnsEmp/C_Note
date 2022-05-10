#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(), ans = 0;
        sort(tasks.begin(), tasks.end());
        for(int i = 0;i < n;++i) {
            auto j = upper_bound(tasks.begin(), tasks.end(), tasks[i]) - tasks.begin() - 1;
            int cnt = j - i + 1;
            // if(cnt % 10 == 1) return -1;
            // else {
            int t = 0;
            for(t = cnt / 3;t >= 0;t--) {
                if((cnt - t * 3) % 2 == 0) {
                    ans += t + (cnt - t * 3) / 2;
                    break;
                }
            }
            if(t == -1) return -1;
            // }
            i = j;
        }
        return ans;
    }
};