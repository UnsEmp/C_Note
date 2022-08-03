#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
string s;
int n;

class strhash {
    public:
        int n;
        string s;
        vector<unsigned long long> h, p;

        strhash(int _n, string _s) : n(_n), s(_s) {
            h.resize(n, 0), p.resize(n, 0);
            p[0] = 1;
            for(int i = 1;i <= s.size();++i) {
                h[i] = h[i - 1] * 131 + (s[i - 1] - 'a' + 1);
                p[i] = p[i - 1] * 131;
            }
        }
        
        inline unsigned long long val(int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1]; 
        }
};

void SA(vector<int> &sfx, string &s) {
    strhash st(N, s);
    iota(sfx.begin(), sfx.end(), 0);
    sort(sfx.begin(), sfx.end(), [&](int a, int b) {
        int l = 0, r = n - max(a, b);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(st.val(a + 1, a + mid) == st.val(b + 1, b + mid)) l = mid;
            else r = mid - 1;
        }
        int vl = a + l >= n?INT_MIN:s[a + l], vr = b + l >= n?INT_MIN:s[b + l];
        return vl < vr;
    });
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    strhash st(N, s);
    vector<int> sfx(n);
    iota(sfx.begin(), sfx.end(), 0);
    sort(sfx.begin(), sfx.end(), [&](int a, int b) {
        int l = 0, r = n - max(a, b);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(st.val(a + 1, a + mid) == st.val(b + 1, b + mid)) {
                l = mid;
            }
            else r = mid - 1;
        }
        int vl = a + l >= n?INT_MIN:s[a + l], vr = b + l >= n?INT_MIN:s[b + l];
        return vl < vr;
    });
    for(int i = 0;i < n;++i) cout << sfx[i] << " \n"[i == n - 1];
    cout << 0 << " ";
    for(int i = 1;i < n;++i) {
        int l = 0, r = n - max(sfx[i], sfx[i - 1]);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(st.val(sfx[i] + 1, sfx[i] + mid) == st.val(sfx[i - 1] + 1, sfx[i - 1] + mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << " \n"[i == n - 1];
    }
    return 0;
}