#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> arr;
        int n = words.size();
        for(int i = 0;i < n;) {
            int j = i;
            int count = 0;
            string s = "";
            while(j < n && count + words[j].size() <= maxWidth && (j - i) <= maxWidth - (count + size)) {
                count += words[j].size();
                j++;
            }
            if(j != n) {
                for(int t = i;t < j;t++) {
                    s += words[t];
                    if(t != j - 1) {
                        for(int k = 0;k < (maxWidth - count) / (j - i - 1);k++) {
                            s += " ";
                        }
                    }
                }
            }
            else {
                for(int t = i;t < j;t++) {
                    s += words[t];
                    if(t != j - 1)
                        s += " ";
                }
                while(s.size() < maxWidth) {
                    s += " ";
                }
            }
            int tmp = 0;
            if((j - i) == 1) {
                while(s.size() < maxWidth) {
                    s += " ";
                }
            }
            else {
                for(int t = i;t < j - 1 && s.size() < maxWidth;t++) {
                    tmp += words[t].size();
                    s.insert(tmp + (t - i), " ");
                    tmp += (maxWidth - count) / (j - i - 1);
                }
            }
            i = j;
            arr.push_back(s);
        }
        return arr;
    }
};

int main() {
    Solution so;
    vector<string> arr = {"a"};
    vector<string> ans;
    int m = 1;
    ans = so.fullJustify(arr, m);
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << endl;
    }
    return 0;
}