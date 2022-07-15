#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());

        int ans = 0, pos = 0;
        int a = amount[0], b = amount[1], c = amount[2];
        if(a + b <= c) {
            ans += c;
        }
        else {
            while(c > 0) {
                if(a > b) {
                    a --;
                }
                else {
                    b --;
                }
                c --;
                ans ++;
            }
            int t = min(a, b);
            ans += t;
            ans += max(a, b) - t;
        }
        return ans;

        // int t = abs(a - b);
        // c -= t;
        // ans += t;
        // ans += min(a, b);
        // ans += c;
        // return ans;
    }
};