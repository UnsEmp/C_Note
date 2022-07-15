#include <bits/stdc++.h>
using namespace std;
using ll = long long;


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    int step = 0, ans = INT_MAX;
    queue<ll> q;
    set<ll> st;
    q.push(x);
    st.insert(x);
    int hash[10];
    while(q.size()) {
        int len = q.size();
        for(int i = 0;i < len;++i) {
            auto t = q.front();
            q.pop();
            if(to_string(t).size() >= n) {
                cout << step << "\n";
                return 0;
            }
            memset(hash, 0, sizeof hash);
            for(auto j = t;j;j /= 10) {
                int si = (j % 10);
                if(st.count(t * si)) continue;
                if(si != 1 && !hash[si]) {
                    hash[si] ++;
                    q.push(t * si);
                    st.insert(t * si);
                }
            }
        }
        step ++;
    }
    cout << "-1" << "\n";
}
