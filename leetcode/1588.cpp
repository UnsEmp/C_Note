#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(auto & a : arr) {
            sum += a;
        }
        for(int len = 3;len <= arr.size();len += 2) {
            for(int i = 0;i <= arr.size() - len;i++) {
                for(int j = i;j < len + i;j++) {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};