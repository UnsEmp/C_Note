#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> edge(110);
        for(int i = 0;i < rectangles.size();++i) {
            edge[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        vector<int> ans;
        for(int i = 0;i < points.size();++i) {
            int cnt = 0;
            for(int j = points[i][1];j <= 100;++j) {
                int t = lower_bound(edge[j].begin(), edge[j].end(), points[i][0]) - edge[j].begin();
                cnt += edge[j].size() - t;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};