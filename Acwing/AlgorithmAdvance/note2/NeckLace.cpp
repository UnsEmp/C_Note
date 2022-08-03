#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 2e6 + 10;
ull h[N], p[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    string s, s1, s2;
    cin >> s1 >> s2;
    s = s1 + s1 + s2;
    int n = s1.size(), m = s.size();
    bool flag = false;
    ull ha;
    memset(h, 0, sizeof h);
    memset(p, 0, sizeof p);
    p[0] = 1;
    for(int i = 0;i < m;++i) {
        h[i + 1] = h[i] * 131 + (s[i] - '0');
        p[i + 1] = p[i] * 131;
    }
    for(int i = 0;i < n;++i) {
        if(get(i + 1, i + n) == get(2 * n + 1, m)) {
            flag = true;
            break;
        }
    }

    if(!flag) cout << "No\n";
    else {
        cout << "Yes\n";
        int i = 0, j = 1;
        for(;i <= n && j <= n;) {
            int k = 0;
            while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) {
                ++k;
            }
            if(k == n) {
                break;
            }
            if(s[i + k] > s[j + k]) {
                i = i + k + 1;
                if(i == j) i ++;
            }
            else {
                j = j + k + 1;
                if(i == j) j ++;
            }
        }
        cout << s.substr(min(i, j), n);
    }
    return 0;
}