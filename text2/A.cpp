#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> nums, prifix;
    prifix.push_back(0);
    ll i = 0, ans = LONG_LONG_MIN;
    for(i = 0;i < n;++i) {
        ll t;
        cin >> t;
        nums.push_back(t);
        prifix.push_back(prifix[i] + nums[i]);
    }
    
    deque<ll> q;
    for(i = 0;i < n;++i) {
        while(q.size() && i - q.front() + 1 > m) q.pop_front();
        
        if(q.size()) {
            cout << q.front() << " " << i << "\n";
            // cout << i << " " << q.front() << "\n";
            ans = max(ans, prifix[i + 1] - prifix[q.front()]);
        }
        else {
            ans = max(ans, nums[i]);
        }
        while(q.size() && prifix[i + 1] <= prifix[q.back() + 1]) q.pop_back();
        q.push_back(i);
        // ans = max(ans, prifix[i + 1] - prifix[q.front()]);
    }
    cout << ans << "\n";
    return 0;
}