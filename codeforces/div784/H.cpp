#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[32];
    memset(arr, 0, sizeof arr);
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        for(int j = 30;j >= 0;--j) {
            if((t >> j) & 1) {
                arr[j] ++;
            }
        }
    }
    int ans = 0;
    for(int i = 30;i >= 0;--i) {
        if(k >= (n - arr[i])) {
            ans += (1 << i);
            k -= (n - arr[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}