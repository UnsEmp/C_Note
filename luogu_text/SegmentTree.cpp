#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

vector<ll> a(N), tree(N << 2), mark(N << 2);
ll n, m;
void build(ll l, ll r, ll p) {
    if(l >= r) {
        tree[p] = a[l];
        return ;
    }
    ll mid = l + (r - l) / 2;
    build(l, mid, p * 2), build(mid + 1, r, p * 2 + 1);
    tree[p] = tree[p * 2 + 1] + tree[p * 2];
}

void update(ll l, ll r, ll c, ll s, ll t, ll p) {
    if(l <= s && t <= r) {
        tree[p] += (t - s + 1) * c, mark[p] += c; 
        return ;
    }
    ll mid = s + (t - s) / 2;
    if(mark[p]) {
        tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
        mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
        mark[p] = 0;
    }
    if(l <= mid) update(l, r, c, s, mid, p * 2);
    if(mid < r) update(l, r, c, mid + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

ll getsum(ll l, ll r, ll s, ll t, ll p) {
    if(l <= s && t <= r) {
        return tree[p];
    }
    ll mid = s + (t - s) / 2;
    if(mark[p]) {
        tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
        mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
        mark[p] = 0;
    }
    ll sum = 0;
    if(l <= mid) sum += getsum(l, r, s, mid, p * 2);
    if(mid < r) sum += getsum(l, r, mid + 1, t, p * 2 + 1);
    return sum; 
}



int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    build(1, n, 1);
    while(m--) {
        ll t, x, y, k;
        cin >> t;
        if(t == 1) {
            cin >> x >> y >> k;
            update(x, y, k, 1, n, 1);
        }
        else {
            cin >> x >> y;
            cout << getsum(x, y, 1, n, 1) << "\n";
        }
    }
    return 0;
}