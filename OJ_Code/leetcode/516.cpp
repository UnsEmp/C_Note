#include <bits/stdc++.h>
using namespace std;

//DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> arr(1010, vector<int>(1010));
         for(int len = 1;len <= s.size();len++) {
             for(int left = 0;left + len - 1 < n;left++) {
                 int right = left + len - 1;
                 int temp = right - left + 1;
                 if(temp == 1) {
                     arr[left][right] = 1;
                 }
                 else if(temp == 2) {
                     if(s[left] == s[right]) {
                        arr[left][right] = 2;
                     }
                     else {
                        arr[left][right] = 1;
                     }
                 }
                 else {
                     arr[left][right] = max(arr[left + 1][right], arr[left][right - 1]);
                     arr[left][right] = max(arr[left][right], arr[left + 1][right - 1] + ((s[left] == s[right])?2:0));
                 }
             }
         }
         return arr[0][n - 1];
    }
};