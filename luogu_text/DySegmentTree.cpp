#include <bits/stdc++.h>
#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define mark(x) tree[x].mark
#define val(x) tree[x].val
using namespace std;
using ll = long long;
const int N = 1e6;
const int L = 1;
const int R = 1e5;
ll n, q, cnt = 1;
struct node {
    ll val = 0, mark = 0;
    int ls, rs;
}tree[N];


void push_down(ll p, ll len) {
    if(len <= 1) return ;
    if(!ls(p)) ls(p) = ++cnt;
    if(!rs(p)) rs(p) = ++cnt;
    mark(ls(p)) += mark(p);
    val(ls(p)) += mark(p) * (len / 2);
    mark(rs(p)) += mark(p);
    val(rs(p)) += mark(p) * (len - len / 2);
    mark(p) = 0;
}

ll getsum(ll l ,ll r, ll p = 1, ll lc = L, ll rc = R) {
    if(l <= lc && rc <= r) return val(p);
    push_down(p, rc - lc + 1);
    ll mid = (rc + lc - 1) / 2, sum = 0;
    if(l <= mid) sum += getsum(l, r, ls(p), lc, mid);
    if(mid < r) sum += getsum(l, r, rs(p), mid + 1, rc);
    return sum;
}

void update(ll l, ll r, ll d, ll p = 1, ll lc = L, ll rc = R) {
    if(l <= lc && rc <= r) return val(p) += d * (rc - lc + 1), mark(p) += d, void();
    push_down(p, rc - lc + 1);  
    ll mid = (lc + rc - 1) >> 1;
    if(l <= mid) update(l, r, d, ls(p), lc, mid);
    if(mid < r) update(l, r, d, rs(p), mid + 1, rc); 
    val(p) = val(ls(p)) + val(rs(p));
}

int main() {
    cin >> n >> q;
    while(q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        if(k == 1) update(l, r, 1);
        else update(l, r, 0);
        cout << getsum(1, n) << "\n";
    }
    return 0;
}