#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>> q;
        vector<int> arr(n + 1);
        fill(arr.begin(), arr.end(), INT_MAX);
        int Max = INT_MAX;
        map<int, vector<pair<int, int>>> mp;
        pair<int, int> tmp, ans;
        for(int i = 0;i < flights.size();i++) {
            tmp.first = flights[i][1];
            tmp.second = flights[i][2];
            mp[flights[i][0]].emplace_back(tmp);
        }
        int step = 0;
        tmp.first = src;
        tmp.second = 0;
        q.push(tmp);
        while(!q.empty() && step < k + 1) {
            int len = q.size();
            for(int i = 0;i < len;i++) {
                pair<int, int> ans = q.front();
                q.pop();
                for(int j = 0;j < mp[ans.first].size();j++) {
                    int num = mp[ans.first][j].first;
                    int money =  mp[ans.first][j].second;
                    tmp.first = num;
                    tmp.second = money + ans.second;
                    if( tmp.second < arr[tmp.first] ) {
                        arr[tmp.first] = tmp.second;
                        q.push(tmp);
                    }
                    if(tmp.first == dst) {
                        Max = min(Max, tmp.second);
                    }
                }
            }
            step++;
        }
        return Max == INT_MAX?-1:Max;
    }
};