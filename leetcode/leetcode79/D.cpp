#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string &s, int l, int r) {
        if(s[l] == '$') {
            // cout << "ok" << "\n";
            int cnt = 0;
            for(int i = l + 1;i <= r;++i) {
                if(s[i] == '$') return false;
            }
            return true;
        }
        return false;
    }
    string discountPrices(string sentence, int discount) {
        int n = sentence.size();
        string ans = "";
        for(int i = 0;i < n;++i) {
            int j = i;
            while(j + 1 < n && sentence[j + 1] != ' ') {
                j ++;
            }
            // string res = "";
            // for(int t = i;t <= j;++t) res += sentence[t];
            // cout << res << "\n";
            if(judge(sentence, i, j)) {
                // cout << "ok" << "\n";
                string res;
                // res = "";
                for(int t = i + 1;t <= j;++t) res += sentence[t]; 
                // string res = sentence.substr(sentence.begin() + i + 1, j - i + 1);
                double d = 1.0 * stoi(res) * (100 - discount) / 100 * 100;
                std::ostringstream oss;
                // res += "$";
                // oss << std::setprecision(4) << d;
                ans += "$";
                res = to_string((ll)d);
                ans += res.substr(0, res.find(".") + 2 + 1) ;
            }
            else {
                for(int t = i;t <= j;++t) ans += sentence[t];
            }
            if(j != n - 1) ans += " ";
            i = j + 1;
        }
        return ans;
    }
};