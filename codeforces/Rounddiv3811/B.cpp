#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int cnt = 0;
    map<int, int> mp;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        if(!mp[nums[i]]) {
            cnt ++;
        } 
        mp[nums[i]] ++;
    }
    int ans = 0;
    for(int i = 0;i < n;++i) {
        if(cnt == n - i) break;
        mp[nums[i]] --;
        if(!mp[nums[i]]) cnt --;
        ans ++; 
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