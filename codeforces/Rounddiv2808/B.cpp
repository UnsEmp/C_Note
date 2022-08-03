#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    // vector<int> nums(n);
    if((r - l + 1) < n) {
        cout << "NO" << "\n";
        return ;
    }
    int nums[n + 1];
    map<int, int> mp;
    memset(nums, 0, sizeof nums);
    // nums[1] = l;
    for(int i = n;i >= 1;--i) {
        int t = l;
        if(t % i != 0) {
            t += (i - (t % i));
        }
        while(t <= r && mp[t]) {
            t += i;
        }
        if(t > r) {
            cout << "NO" << "\n";
            return ;
        }
        else {
            mp[t] ++;
            nums[i] = t;
        }
    }
    cout << "YES" << "\n";
    for(int i = 1;i <= n;++i) cout << nums[i] << " ";
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