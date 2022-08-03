#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, c, q;
ll search(vector<pair<ll, ll>> &tr, vector<pair<ll, ll>> &fa, ll id) {
    ll l = 0, r = fa.size() - 1;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(id >= fa[mid].first) l = mid;
        else r = mid - 1;
    }
    return tr[l].first + (id - fa[l].first);
}

void solve() {
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<pair<ll, ll>> tr(c + 1), fa(c + 1);
    tr[0].first = fa[0].first = 1;
    tr[0].second = fa[0].second = n;
    ll l = 1, r = n, a, b;
    for(int i = 1;i <= c;++i) {
        cin >> a >> b;
        l = r + 1, r = l + (b - a);
        fa[i].first = l, fa[i].second = r;
        tr[i].first = a, tr[i].second = b;
    }
    while(q--) {
        ll id, t;
        cin >> id;
        t = id;
        while(t > n) {
            t = search(tr, fa, t);
        }
        cout << s[t - 1] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}