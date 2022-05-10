#include <bits/stdc++.h>
using namespace std;

const int N = 35;
vector<int> nums(N);

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
    }
    int ans = 0;
    if(n == 1) {
        cout << "0" << "\n";
        return ;
    }
    if(nums[n - 1] < n - 1) {
        cout << "-1" << "\n";
        return ;
    }

    for(int i = n - 2;i >= 0;--i) {
        if(nums[i] < i) {
            cout << "-1" << "\n";
            return ;
        }
        while(nums[i] >= nums[i + 1]) {
            nums[i] /= 2;
            ans ++;
        } 
        if(nums[i] == 0 && i != 0) {
            cout << "-1" << "\n";
            return ;
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