#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> nums(4);
    for(int i = 0;i <= n - m;++i) {
        if(a[i] == '0') nums[0] = 1;
        else nums[1] = 1;
    }
    // for(int i = 0;i < m;++i) {
    //     if(b[i] == '0') nums[2] = 1;
    //     else nums[3] = 1;
    // }
    for(int i = n - m + 1;i < n;++i) {
        if(a[i] != b[i - (n - m + 1) + 1]) {
            cout << "NO" << "\n";
            return ;
        }
    }
    // if((nums[0]))
    // if(nums[0] < nums[2] && nums[1] < nums[3]) {
    //     cout << "NO" << "\n";
    //     return ;
    // }
    // for(int i = 1;i < n - m;++i) {
    //     int ma, mi;
    //     ma = max(a[i] - '0', a[i - 1] - '0');
    //     mi = min(a[i] - '0', a[i - 1] - '0');
    //     if(nums[0] > nums[2]) {

    //     }
    // }
    if(nums[b[0] - '0']) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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