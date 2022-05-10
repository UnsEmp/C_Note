#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    // map<pair<int,int>, int> mp;
    set<pair<int,int>> st;
    void add(int x, int y, int r) {
        // int upx = x + r, upy = y;
        // for(int i = upx;i >= x;--i) {
        //     for(int j = y - (upx - i);j <= y + (upx - i);++j) {
        //         // cout << i << " " << j << "\n";
        //         // mp[{i, j}] ++;
        //         st.insert({i, j});
        //     }
        // }
        // for(int i = x - 1;i >= x - r;--i) {
        //     for(int j = (x - r) + (x - i);j <= (y + r) - (x - i);++j) {
        //         // cout << i << " " << j << "\n";
        //         // mp[{i, j}] ++;
        //         st.insert({i, j});
        //     }
        // }
        for(int i = x + r;i >= x - r;--i) {
            for(int j = y - r;j <= y + r;++j) {
                if((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                    st.insert({i, j});
                }
            }
        }
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size(), m = circles[0].size();
        for(int i = 0;i < n;++i) {
            add(circles[i][0], circles[i][1], circles[i][2]);    
        }
        // int ans = 0;
        // for(auto m : mp) ans ++;
        return st.size(); 
    }
};