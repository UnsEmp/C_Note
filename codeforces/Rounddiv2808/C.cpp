#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n), ans(n);
    int i, j;
    for(i = 0;i < n;++i) {
        cin >> nums[i];
        if(nums[i] <= q) {
            ans[i] = 1;
        }
    }
    for(i = 0;i < n;++i) {
        if(nums[i] < q) continue;
        j = i;
        while(j < n && nums[j] > q) {
            j++;
        }
        int t = j - i;
        if(q)
        // for(t = i;t <= i + )
    }
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