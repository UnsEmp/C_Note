#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
 
// vector<ll> a(N), tree(N << 2), mark(N << 2);
ll a[N], tree[N << 2], mark[N << 2];
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
 
void solve() {
	ll n, k, sum = 0;
    scanf("%lld", &n);
    memset(tree, 0, sizeof tree);
    memset(mark, 0, sizeof mark);
	for(int i = 1;i <= n;++i) {
        scanf("%lld", &a[i]);
		sum += a[i];
	}
	build(1, n, 1);
	k = sum / n;
    ll ans[n + 1];
    memset(ans, 0, sizeof ans);
	for(int i = n;i > 0;--i) {
        update(i - k + 1, i, -1, 1, n, 1);
		if(k > 0) {
			ll t = getsum(i, i, 1, n, 1);
			if(t == i - 1) {
				ans[i] = 1;
				k --;
			} 
			else {
				ans[i] = 0;
			}
		}
		else break;
	}
	for(int i = 1;i <= n;++i) cout << ans[i] << " ";
	cout << "\n"; 
}
 
 
int main() {
    // ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	int _;
	// cin >> _;
    scanf("%d", &_);
	while(_--) {
		solve();
	}
    return 0;
}