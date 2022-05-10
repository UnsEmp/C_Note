#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int ,int>;
using VI = vector<int>;
using VII = vector<vector<int>>;
using VL = vector<ll>;
using VLL = vector<vector<ll>>;


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

const int N = 110;
ll a[N];

ll mex(int l, int r) {
    for(int i = x)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        ll n, sum = 0;
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int len = 1;len <= n;len ++) {
            for(int i = 0;i + len - 1 < n;i++) {
                sum += mex(i, i + len - 1);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}