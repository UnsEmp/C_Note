#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 1e6 + 10;

class strhash {
    public:
        int n;
        string s;
        vector<unsigned> h, p;

        strhash(int _n, string _s) : n(_n), s(_s) {
            h.resize(n, 0), p.resize(n, 0);
            p[0] = 1;
            for(int i = 1;i <= s.size();++i) {
                h[i] = h[i - 1] * 131 + (s[i - 1] - 'a' + 1);
                p[i] = p[i - 1] * 131;
            }
        }
        
        inline unsigned val(int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1]; 
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    strhash st(N, s);
    int _;
    cin >> _;
    while(_--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(st.val(a, b) == st.val(c, d)) cout << "Yes" << "\n";
        else cout << "No" << "\n"; 
    }
    return 0;
}