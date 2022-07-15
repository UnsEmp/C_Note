#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> pos(n);
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        pos[i] = i;
    }
    if(n == k) {
        cout << "0" << "\n";
        return ;
    }
    sort(pos.begin(), pos.end(), [&](int a, int b) {
        return nums[a] + a > nums[b] + b;
    });
    for(int i = 0;i < k;++i) {
        nums[pos[i]] = -1;
    }
    ll sum = 0, res = 0;
    for(int i = 0;i < n;++i) {
        if(nums[i] == -1) res ++;
        else sum += (nums[i] + res);
    }
    cout << sum << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}