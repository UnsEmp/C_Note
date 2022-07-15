#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    set<pair<int,int>> st;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        st.insert({nums[i], t});
    }
    int r = -1;
    vector<int> arr;
    for(auto &s : st) {
        if(s.first > r) arr.push_back(s.second - s.first);
        else if(r > s.second) arr.push_back(0);
        else arr.push_back(s.second - r);
        r = s.second;
    }
    for(int i = 0;i < n;++i) {
        cout << arr[i];
        if(i!=n - 1) cout << " ";
        else cout << "\n";
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