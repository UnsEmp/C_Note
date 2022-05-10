#include <bits/stdc++.h>
using namespace std;
typedef long long int;


class Solution {
public:
    bool check(vector<int> &candies, long long k, int x, int sum, int n) {
        int count = 0;
        for(int j = x;;j += x) {
            auto t = lower_bound(candies.begin(), candies.end(), j) - candies.begin();
            if(t >= n) break;
            count += (n - t); 
        }
        if(count >= k) {
            return true;
        }
        else {
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        sort(candies.begin(), candies.end());
        int ans = 0;
        int len = candies[n - 1];
        int l = 1, r = len;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(candies, k, mid, len, n)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};