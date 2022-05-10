#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<long long> arr;
    long long f(int l, int r) {
        return arr[r] - arr[l - 1];
    }
    long long numberOfWays(string s) {
        int n = s.size();
        // vector<int> tree(n + 1);
        arr.push_back(0);
        for(int i = 0;i < n;++i) {
            arr.push_back(arr[i] + (s[i] - '0'));
        }
        long long ans = 0;
        for(int i = 0;i < n;++i) {
            if(s[i] == '0') ans += f(1, i + 1) * f(i + 1, n);
            else ans += ((i + 1) - f(1, i + 1)) * ((n - i) - f(i + 1, n));
        } 
        return ans;
    }
};