#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> arr(n + 1);
    int t, l, r;
    for(int i = 1;i <= n;++i) {
        cin >> t;
        if(!t) {
            l = i + 1, r = n;
        }
        else {
            l = i / (t + 1) + 1, r = i / t;
        }
        arr[l].emplace_back(r, i);
        cout << l << " " << r << " " << i << "\n";
    }
    set<pair<int, int>> st;
    vector<int> ans(n);
    for(int i = 0;i < n;++i) {
        for(auto & j : arr[i + 1]) {
            st.insert({j.first, j.second});
        }
        ans[st.begin()->second - 1] = i + 1;
        st.erase(st.begin());
    }
    for(int i = 0;i < n;++i) cout << ans[i] << " ";
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