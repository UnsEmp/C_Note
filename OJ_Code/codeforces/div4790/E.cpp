#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    vector<ll> prifix;
    vector<ll> nums;
    prifix.push_back(0);
    cin >> n >> m;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        nums.push_back(t);
        // prifix.push_back(prifix[i] + t);
    }
    sort(nums.begin(), nums.end(), greater<ll>());
    for(int i = 0;i < n;++i) {
        prifix.push_back(prifix[i] + nums[i]);
    }
    while(m--) {
        int q;
        cin >> q;
        if(q > prifix[n]) {
            cout << "-1" << "\n";
            continue;
        }
        auto t = lower_bound(prifix.begin(), prifix.end(), q) - prifix.begin();
        cout << t << "\n";
    }

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