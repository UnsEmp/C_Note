#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> mp;
    map<string, int> mmp;
    vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> brr = {"zero", "two", "four", "five", "six" , "eight", "one", "three","seven", "nine" };
    int judge(string s) {
        int Min = INT_MAX;
        for(int i = 0;i < s.size();i++) {
            Min = min(Min, mp[s[i]]);
        }
        return Min;
    }
    int trans(string s) {
        return mmp[s];
    }
    string originalDigits(string s) {
        vector<int> ans;
        for(int i = 0;i < 10;i++) mmp[arr[i]] = i;
        for(int i = 0;i < s.size();i++) mp[s[i]]++;
        for(int i = 0;i < 10;i++) {
            int top = judge(brr[i]);
            if(top != 0) {
                for(int j = 0;j < brr[i].size();j++) {
                    mp[brr[i][j]] -= top;
                }
                for(int k = 0;k < top;k++) ans.push_back(trans(brr[i]));
            }
        }
        sort(ans.begin(), ans.end());
        string an;
        for(int i = 0;i < ans.size();i++) an += ans[i] + '0';
        return an;
    }
};

int main() {
    Solution so;
    deque<int> q;
    q.back
    string s = "zeroonetwothreefourfivesixsevennineeight";
    cout << so.originalDigits(s) << endl;
    return 0;
}