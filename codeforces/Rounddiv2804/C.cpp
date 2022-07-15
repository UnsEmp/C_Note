#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    vector<int> p(n);
    for(int i = 0;i < n;++i) p[nums[i]] = i;
    int ma = p[0], mi = p[0];
    long long ans = 1;
    for(int i = 1;i < n;++i) {
        if(p[i] < mi) mi = p[i];
        else if(p[i] > ma) ma = p[i];
        else ans = ans * (ma - mi + 1 - i) % mod;
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