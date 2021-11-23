#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = n - 1;i > 0;i--) {
            for(int j = i;j > 0;j--) {
                            // cout << i << " " << j << endl;
                triangle[i - 1][j - 1] += min(triangle[i][j], triangle[i][j - 1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution so;
    vector<vector<int>> arr = {{2},{3, 4},{6,5,7},{4,1,8,3}};
    cout << so.minimumTotal(arr);
    return 0;
}