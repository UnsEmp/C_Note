#include <bits/stdc++.h>
using namespace std;

int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.rbegin(), properties.rend());
        int ans = 0, bhi = 0, last = 0;
        for (int i = 0; i < n; i++) {
            int a = properties[i][0], b = properties[i][1];
            if (i > 0 && a < properties[i - 1][0]) {
                bhi = max(bhi, properties[last][1]);
                last = i;
            }
            if (b < bhi)
                ans++;
        }

        return ans;
    }


int main() {
    vector<vector<int>> arr = {{1, 5}, {10, 4}, {4, 3}};
    cout << numberOfWeakCharacters(arr) << endl;
    // cout << nullptr << endl;
    return 0;
}