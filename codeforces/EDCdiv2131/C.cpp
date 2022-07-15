#include <bits/stdc++.h>
using namespace std;
int n, m;
// vector<int> nums;
// map<int, int> mp;

bool check(int mid, vector<int> &nums) {
    int sum = 0;
    for(int i = n - 1;i >= 0;--i) {
        if(nums[i] > mid) sum += (nums[i] - mid);
        else break;
    }
    if(sum <= 0) return true;
    for(int i = 0;i < n;++i) {
        int t = mid - nums[i];
        sum -= t / 2;
        if(sum <= 0) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0;i < m;++i) {
        int t;
        cin >> t;
        nums[t - 1] ++;
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = 4e5 + 10;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid, nums)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
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