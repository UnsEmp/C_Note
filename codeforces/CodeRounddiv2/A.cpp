#include <bits/stdc++.h>
using namespace std;

void solve() {
    int odd = 0, even = 0;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        if(nums[i] % 2 == 0) even ++;
        else odd ++;
    }
    cout << min(odd, even) << "\n";
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