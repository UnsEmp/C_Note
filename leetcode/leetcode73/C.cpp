#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;


template <typename T, typename W>
vector<int> KMP(T &p, T &s, W m, W n) {
    unordered_map<W, W> ne;
    vector<W> ans;
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}



#define N 2500
class Solution {

public:
    int h[N], e[N], ne[N],d[N], idx = 0;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> & edges) {
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        for(int i = 0;i < edges.size();++i) {
                add(edges[i][0], edges[i][1]);
                ++ d[edges[i][1]];
        }
        queue<int> q;
        vector<set<int>> arr(n);    
        unordered_map<int, int> mp;
        for(int i = 0;i < n;i++) {
            if(!d[i]) {
                q.push(i);
                ++ mp[i];
            }
        }

        while(!q.empty()) {
            int len = q.size();
            for(int i = 0;i < len;i++) {
                auto t = q.front();
                q.pop();
                for(int i = h[t];i != -1;i = ne[i]) {
                    int j = e[i];
                    arr[j].insert(t);
                    -- d[j];
                    for(auto a : arr[t]) arr[j].insert(a);
                }
            }
            for(int i = 0;i < n;i++)
                if(!mp[i] && !d[i]) {
                    q.push(i);
                    ++ mp[i];
                }
        }
        vector<vector<int>> ans(n);
        for(int i = 0;i <n;++i) ans[i] = {arr[i].begin(), arr[i].end()};
        return ans;
    }

};

int main() {
    // cout << "hello" << endl;
    Solution so;
    vector<vector<int>> arr = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7},{4, 6}};
    auto brr = so.getAncestors(8, arr);
    for(int i = 0;i < brr.size();i++) {
        for(int j = 0;j < brr[i].size();j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}