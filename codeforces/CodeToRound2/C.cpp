#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(m), arr(m);
    for(int i = 0;i < m;++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    arr[0] = nums[0] - 1 + (n - nums[m - 1]);
    for(int i = 1;i < m;++i) {
        arr[i] = nums[i] - nums[i - 1] - 1;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int sum = 0, t = 0;
    for(int i = 0;i < m;++i) {
        if(arr[i] <= 2 * t) continue;
        int tmp = arr[i] - (2 * t);
        if(tmp > 1) {
            sum += (arr[i] - (2 * t) - 1);
        }
        else {
            sum ++;
        }
        t += 2;
    }
    cout << n - sum << "\n";
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