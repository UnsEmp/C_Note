#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long t = 0;
        map<long long, long long> mp; 
        long long n = tasks.size();
        for(int i = 0;i < n;++i) {
            t ++;
            mp[tasks[i]] = t;
            long long j = i + 1;
            while(j < n && (mp[tasks[j]] == 0 || ((t + 1) - mp[tasks[j]] > space))) {
                mp[tasks[j]] = ++t;
                j ++;
            }
            if(j < n) {
                t += (space - ((t + 1) - mp[tasks[j]]) + 1);
            }
            i = j - 1;
        }
        return t;
    }
};