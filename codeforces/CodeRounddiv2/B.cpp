#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp, sign;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        mp[nums[i]] ++;
    }
    for(auto m : mp) {
        if(m.second == 1) {
            cout << "-1" << "\n";
            return ;
        }
    }
    vector<int> ans(n + 1);
    for(int i = 0;i < n + 1;++i) ans[i] = i;
    
    for(int i = 0;i < n;++i) {
        if(!sign[nums[i]]) {
            sign[nums[i]] = i + 1;
            ans[i + 1] = i + 1;
        }
        else {
            ans[i + 1] = i + 1;
            swap(ans[sign[nums[i]]], ans[i + 1]);
            sign[nums[i]] = i + 1;
        }
    }
    for(int i = 1;i <= n;++i) cout << ans[i] << " ";
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