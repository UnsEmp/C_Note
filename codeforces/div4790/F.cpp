#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int l = -1, r = -1;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    if(k == 1) {
        int ans = 0;
        for(int i = 0;i < n;++i) {
            int j = i + 1;
            while(j < n && (nums[j] == nums[j - 1] || nums[j - 1] + 1 == nums[j])) {
                if(nums[j] - nums[i] > r - l) {
                    l = nums[i], r = nums[j];
                }
                j++;
            }
            i = j - 1;
        }
        cout << l << " " << r << "\n";
        return ;
    }
    for(int i = 0;i < n;i++) {
        int j = i + k - 1;
        while(j < n && nums[j] == nums[j - (k - 1)]) {
            if(nums[j] - nums[i] > r - l) {
                l = nums[i], r = nums[j];
            }
            while(j < n && nums[j] == nums[j - 1]) j++;
            j += (k - 1);
        }
        i = j - 1;
    }
    if(l == -1) cout << "-1" << "\n";
    else cout << l << " " << r << "\n";
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