#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> arr(55);
        for(int i = 0;i < ranges.size();i++) {
            arr[ranges[i][0]]++;
            arr[ranges[i][1] + 1]--;
        }
        int sum = 0;
        for(int i = 1;i < 55;i++) {
            sum += arr[i];
            if(sum <= 0 && i >= left && i <= right)
                return false;
        }
        return true;

    }
};