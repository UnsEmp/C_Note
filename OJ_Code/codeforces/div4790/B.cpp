#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    // vector<int> nums(n);
    cin >> n;
    int ma = INT_MAX, sum = 0;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        ma = min(ma, t);
        sum += t;
    }
    cout << sum - n * ma << "\n";
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