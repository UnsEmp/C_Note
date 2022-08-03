#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    map<int, int> sign;
    for(int i = 1;i <= n;++i) {
        cin >> nums[i];
    }
    vector<pair<int, int>> arr(m);
    for(int i = 0;i < m;++i) {
        int a, b;
        cin >> a >> b;
        arr[i].first = a, arr[i].second = b;
        sign[a] ++, sign[b] ++;
    }
    if(m % 2 == 0) {
        cout << "0\n";
        return ;
    }
    int ans = INT_MAX;
    for(int i = 1;i <= n;++i) {
        if((m - sign[i]) % 2 == 0) {
            ans = min(ans, nums[i]);
        }
    }
    for(int i = 0;i < m;++i) {
        if((m - sign[arr[i].first] - sign[arr[i].second] + 1) % 2 == 0) {
            ans = min(ans, nums[arr[i].first] + nums[arr[i].second]);
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