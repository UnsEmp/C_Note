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
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0, top = 0;
    for(int i = 0;i < m;i++) {
        ll t;
        cin >> t;
        t--;
        if(t > top) {
            ans += (t - top);
            top = t;
        }
        else if(t < top) {
            ans += (t + n - top);
            top = t;
        }
    }
    cout << ans << endl;

    return 0;
}

