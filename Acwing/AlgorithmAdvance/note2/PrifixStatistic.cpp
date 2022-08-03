#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
class DicTree {
    public:
        vector<vector<int>> tree;
        vector<int> cnt;
        int idx = 0, n;
        DicTree(int _SIZE) : n(_SIZE) {
            tree.resize(n);
            cnt.resize(n);
            for(int i = 0;i < n;++i) tree[i].resize(26);
        }
        inline void insert(string &s) {
            int p = 0;
            for(int i = 0;i < s.size();++i) {
                int u = s[i] - 'a';
                if(!tree[p][u]) {
                    tree[p][u] = ++idx;
                }
                p = tree[p][u]; 
            }
            cnt[p] ++;
        } 
        inline int query(string &s) {
            int p = 0, sum = 0;
            for(int i = 0;i < s.size();++i) {
                int u = s[i] - 'a';
                if(!tree[p][u]) return sum;
                p = tree[p][u];
                sum += cnt[p];
            }
            return sum;
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    DicTree tr(N);
    string s;
    for(int i = 0;i < n;++i) {
        cin >> s;
        tr.insert(s);
    }
    for(int i = 0;i < m;++i) {
        cin >> s;
        cout << tr.query(s) << "\n";
    }
    return 0;
}