#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i = 9;i >= 0;--i) {
            string s = "";
            for(int j = 0;j < 3;++j) s += '0' + i;
            if(num.find(s, 0) != string::npos) {
                ans = s;
            }
        }      
        return ans;
    }
};