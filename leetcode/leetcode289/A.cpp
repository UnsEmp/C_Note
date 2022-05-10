#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(n > k) {
            string res;
            int i;
            for(i = k;i < n;i += k) {
                int sum  = 0 ;
                for(int j = i - k;j < i && j < n;++j) {
                    sum += (s[j] - '0');
                }
                res += to_string(sum);
            }
            sum = 0;
            for(;i < n;++i) {
                sum += (s[i] - '0');
            } 
            res += to_string(sum);
            s = res;
            n = s.size();
        }        
        return s;
    }
};