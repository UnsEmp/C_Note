#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        vector<int> prifix;
        int n = tiles.size(), ans = 0;
        prifix.push_back(0);
        sort(tiles.begin(), tiles.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        for(int i = 0;i < n;++i) {
            prifix.push_back(prifix[i] + (tiles[i][1] - tiles[i][0] + 1));
            // cout << prifix[i + 1] << " ";
        }
        // cout << "\n";
        for(int i = 0;i < n;++i) {
            int l = i, r = n - 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(tiles[i][0] + carpetLen - 1 >= tiles[mid][0]) l = mid;
                else r = mid - 1;
            }
            cout << i << " " << l << "\n";
            int sum = 0;
            int t = tiles[i][0] + carpetLen - 1;
            if(tiles[l][1] >= t) sum += tiles[l][1] - tiles[l][0] + 1;
            else sum += t - tiles[l][0] + 1;
            sum += prifix[l] - prifix[i];
            ans = max(ans, sum); 
        }
        return ans;
    }
};