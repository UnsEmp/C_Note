#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    int ans = 0;
    for(int i = 0;i < n;++i) {
        int j = i + 1;
        int l = nums[i] - x, r = nums[i] + x;
        while(j < n) {
            l = max(l, nums[j] - x);
            r = min(r, nums[j] + x);
            if(l > r) break;
            j ++;
        }
        ans ++;
        i = j - 1;
    }
    cout << max(0, ans - 1) << "\n";
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