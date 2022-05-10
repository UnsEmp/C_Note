#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string s1, string s2) {
        return s1 < s2;
    }
    string removeDigit(string number, char digit) {
        vector<string> nums;
        for(int i = 0;i < number.size();++i) {
            string s = number;
            if(number[i] == digit) {
                s.erase(s.begin() + i);
                nums.push_back(s);
            }
        }
        string ma = nums[0];
        for(int i = 1;i < nums.size();++i) {
            if(judge(ma, nums[i])) ma = nums[i];
        }
        return ma;
    }
};