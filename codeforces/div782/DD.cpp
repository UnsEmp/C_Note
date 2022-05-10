#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int N;
template<class T>
class segment_tree {
private:
    vector<T> sum_st;
    vector<T> lazy;
    vector<T> tag;
    void update(int p) {
        sum_st[p] = sum_st[p * 2 + 1] + sum_st[p * 2 + 2];
    }

    T ret_val(T left, T right) {
        return left + right;
    }

    void down(int l, int r, int p) {
        if (!tag[p]) return;
        int m = (l + r) >> 1;
        lazy[p * 2 + 1] += lazy[p];
        lazy[p * 2 + 2] += lazy[p];
        sum_st[p * 2 + 1] += (m - l) * lazy[p];
        sum_st[p * 2 + 2] += (r - m) * lazy[p];
        tag[p * 2 + 1] = tag[p * 2 + 2] = 1;
        tag[p] = lazy[p] = 0;
    }
public:
    segment_tree(T val = 0) {
        sum_st = vector<T>(N << 2, val);
        lazy = vector<T>(N << 2, val);
    }
    
    segment_tree(const vector<T> &arr, T val = 0) {
        sum_st = vector<T>(N << 2, val);
        lazy = vector<T>(N << 2, val);
        tag = vector<T>(N << 2);
        auto build = [&](auto &build, int l, int r, int p) {
            if (l + 1 == r) {
                if (l < size(arr))
                    sum_st[p] = arr[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(build, l, mid, p * 2 + 1);
            build(build, mid, r, p * 2 + 2);
            update(p);
        };
        build(build, 0, N, 0);
    }

    void change(int l, int r, T val, int cl = 0, int cr = N, int p = 0) {
        if (cl >= r || l >= cr || cl == cr) return;
        if (cl >= l && r >= cr) {
            sum_st[p] = (cr - cl) * val;
            lazy[p] = val;
            tag[p] = 1;
            return;
        }
        down(cl, cr, p);
        int cm = (cl + cr) >> 1;
        change(l, r, val, cl, cm, p * 2 + 1);
        change(l, r, val, cm, cr, p * 2 + 2);
        update(p);
    }

    void add(int l, int r, T delta, int cl = 0, int cr = N, int p = 0) {
        if (cl >= r || l >= cr || cl == cr) return;
        if (cl >= l && r >= cr) {
            sum_st[p] += (cr - cl) * delta;
            lazy[p] += delta;
            tag[p] = 1;
            return;
        }
        down(cl, cr, p);
        int cm = (cl + cr) >> 1;
        add(l, r, delta, cl, cm, p * 2 + 1);
        add(l, r, delta, cm, cr, p * 2 + 2);
        update(p);
    }

    T query(int l, int r, int p = 0, int cl = 0, int cr = N) {
        if (cl >= r || l >= cr || cl == cr) return 0;
        if (cl >= l && r >= cr) return sum_st[p];
        down(cl, cr, p);
        int cm = (cl + cr) >> 1;
        T left = query(l, r, p * 2 + 1, cl, cm);
        T right = query(l, r, p * 2 + 2, cm, cr);
        return ret_val(left, right);
    }
};


void solve() {
	ll n, k, sum = 0;
	cin >> n;
    N = n + 1;
    vector<int> a(n + 1);
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		sum += a[i];
	}
    segment_tree<int> tree(a, 0);
	k = sum / n;
	vector<ll> ans(n + 1);
	for(int i = n;i > 0;--i) {
        int l = i - k + 1;
        int r = i + 1;
        tree.add(l, r, -1);
		if(k > 0) {
			ll t = tree.query(i, i + 1);
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
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _;
	cin >> _;
	while(_--) {
		solve();
	}
    return 0;
}