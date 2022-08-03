#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    // map<int, int> mp;
    bool sign = false;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        if(nums[i] % 5 == 0) sign = true;
    }
    if(sign) {
        if(nums[0] % 5 != 0) {
            cout << "No\n";
            return ;
        }
        nums[0] += (nums[0] % 10);
        for(int i = 1;i < n;++i) {
            nums[i] += (nums[i] % 10);
            if(nums[i] != nums[i - 1] || nums[i] % 5 != 0) {
                cout << "No" << "\n";
                return ;
            }
        }
        cout << "Yes" << "\n";
        return ;
    }
    int ma = 0;
    for(int i = 0;i < n;++i) {
        while((nums[i] % 10) != 6) {
            nums[i] += (nums[i] % 10);
        }
        ma = max(ma, nums[i]);
    }
    for(int i = 0;i < n;++i) {
        int t = ma - nums[i];
        if((t % 20) != 0) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";

    // sort(nums.begin(), nums.end());
    // nums[n - 1] += (nums[n - 1] % 10);
    
    // cout << "Yes" << "\n";
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