#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
class Solution {
public:
    vector<string> ans;
    int son[N][26], idx = 0, n, cnt[N];
    string res;
    void insert(string s) {
        int p = 0;
        for(int i = 0;i < s.size();++i) {
            int u = s[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
                p = idx;
            }
            else p = son[p][u];
        }
        cnt[p] ++;
    }
    void query(int idx, string s) {
        cout << s << "\n";
        if(idx == res.size()) {
            ans.push_back(s);
            return ;
        }
        int p = 0;
        for(int i = idx;i < res.size();++i) {
            int u = res[i] - 'a';
            if(son[p][u]) {
                s += res[i];
                p = son[p][u];
                if(cnt[p]) query(i + 1, s + " ");
            }
            else {
                return ;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = wordDict.size();
        res = s;
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0;i < n;++i) insert(wordDict[i]);
        query(0, "");
        return ans;
    }
};

int main() {
    string s = "bb";
    vector<string> arr = {"a","b","bbb","bbbb"};
    Solution so;
    auto t = so.wordBreak(s, arr);
    for(int i = 0;i < t.size();++i) cout << t[i] << " ";
    cout << "\n";
    return 0;
}