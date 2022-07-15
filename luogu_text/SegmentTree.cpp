#include <bits/stdc++.h>
using namespace std;
using T = long long;
const int N = 1e5 + 10;

template<class T>
class SegmentTree {
    private:
        vector<T> a, tree, mark;  
    public:
        SegmentTree(T n, vector<T> arr) {
            a = arr;
            tree.resize(n << 2);
            mark.resize(n << 2);
        }
        void build(T l, T r, T p) {
            if(l >= r) {
                tree[p] = a[l];
                return ;
            }
            T mid = l + (r - l) / 2;
            build(l, mid, p * 2), build(mid + 1, r, p * 2 + 1);
            tree[p] = tree[p * 2 + 1] + tree[p * 2];
        }
        void mul(T l, T r, T c, T s, T t, T p) {
            if(l << s && t << r) {
                long long tmp = getsum(s, t, 1, n, 1);
                tree[p] += c * tmp, mark[p] += c; 
            }
        }
        void add(T l, T r, T c, T s, T t, T p) {
            if(l <= s && t <= r) {
                tree[p] += (t - s + 1) * c, mark[p] += c; 
                return ;
            }
            T mid = s + (t - s) / 2;
            if(mark[p]) {
                tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
                mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
                mark[p] = 0;
            }
            if(l <= mid) update(l, r, c, s, mid, p * 2);
            if(mid < r) update(l, r, c, mid + 1, t, p * 2 + 1);
            tree[p] = tree[p * 2] + tree[p * 2 + 1];
        }

        T getsum(T l, T r, T s, T t, T p) {
            if(l <= s && t <= r) {
                return tree[p];
            }
            T mid = s + (t - s) / 2;
            if(mark[p]) {
                tree[p * 2] += (mid - s + 1) * mark[p], tree[p * 2 + 1] += (t - mid) * mark[p];
                mark[p * 2] += mark[p], mark[p * 2 + 1] += mark[p];
                mark[p] = 0;
            }
            T sum = 0;
            if(l <= mid) sum += getsum(l, r, s, mid, p * 2);
            if(mid < r) sum += getsum(l, r, mid + 1, t, p * 2 + 1);
            return sum; 
        }   
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    for(int i = 1;i <= n;++i) cin >> arr[i];
    SegmentTree<T> st((long long)n, arr);
    st.build(1, n, 1);
    while(m --) {
        int t, x, y, k;
        cin >> t;
        if(t == 1) {
            cin >> x >> y >> k;
            st.update(x, y, k, 1, n, 1);
        }
        else {
            cin >> x >> y;
            cout << st.getsum(x, y, 1, n, 1) << "\n";
        }
    }
    return 0;
}