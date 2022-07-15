#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> st;
    long long ans = 0;
    for(int i = 1;i <= n;++i) {
        int t;
        cin >> t;
        if(i > t) {
            if(st.size()) {
                int p = lower_bound(st.begin(), st.end(), t) - st.begin();
                p = max(p, 0);
                ans += p;
            }
            st.push_back(i);
        }
    }
    cout << ans << "\n";
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