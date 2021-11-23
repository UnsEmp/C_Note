#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int len = s.size();
        int n = (1 << s.size());
        vector<bool> ans(n);
        int Max = 0;
        // memset(ans.begin(), ans.end(), false);
        fill(ans.begin(), ans.end(), false);
        for(int i = 1;i < n;i++) {
            string sr = "";
            for(int j = len - 1;j >= 0;j--) {
                if((1 << j) & i) sr += s[len - 1 - j];
            }
            if(judge(sr)) ans[i] = true;
        }
        for(int i = 1;i < n;i++) {
            if(ans[i]) {
                for(int j = i + 1;j < n;j++) {
                    if(ans[j] && !(i & j)) {
                        Max = max(Max, __builtin_popcount(i) * __builtin_popcount(j));
                    }
                }
            }
        }
        return Max;
    }
    bool judge(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution so;
    string s = "leetcodecom";
    cout << so.maxProduct(s) << endl;
    return 0;
}