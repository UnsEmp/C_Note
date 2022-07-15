#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    for(int i = 0;i < n;++i) {
        int t, d = 0, u = 0;
        string s;
        cin >> t >> s;
        for(auto & j : s) {
            if(j == 'D') d++;
            else u ++;
        }
        nums[i] = ((nums[i] + d - u) % 10 + 10) % 10;
    }
    for(int i = 0;i < n;++i) cout << nums[i] << " ";
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