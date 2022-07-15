#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int latestTimeCatchTheBus(vector<int>& bu, vector<int>& pa, int ca) {
        // sort(pa.begin(), pa.end());
        sort(bu.begin(), bu.end());
        map<int, int> mp;
        for(int i = 0;i < pa.size();++i) mp[pa[i]] ++;

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0;i < pa.size();++i) q.push(pa[i]);
        int ans = 0;
        for(int i = 0;i < bu.size();++i) {
            int cnt = 0, ma = 0;
            while(cnt < ca && q.size() && q.top() <= bu[i]) {
                ma = max(ma, q.top());
                q.pop();
                cnt ++;
            }
            if(cnt < ca) {
                ma = bu[i];
                while(ma > 0) {
                    if(!mp[ma]) {
                        ans = max(ans, ma);
                        break;
                    }
                    ma --;
                }
            }
            else {
                while(ma > 0) {
                    if(!mp[ma]) {
                        ans = max(ans, ma);
                        break;
                    }
                    ma --;
                }
            }
        }
        return ans;
    }
};