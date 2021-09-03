#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // int Max = 0;
        // if(arr.size() == 1)
        //     return 1;
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1;i < arr.size();i++){
            if(abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
            // int temp = arr[i];
            // Max = max(Max, temp);
        }
        // return Max;
        return arr[arr.size() - 1];
    }
};