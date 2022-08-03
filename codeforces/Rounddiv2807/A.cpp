#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n * 2);
    for(int i = 0;i < n * 2;++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    for(int i = n;i < n * 2;++i) {
        if(nums[i] - nums[i - n] < m) {
            cout << "NO" << "\n";
            return ;
        }
    } 
    cout << "YES" << "\n";
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