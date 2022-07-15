#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    int ma = INT_MAX, even = 0, odd = 0;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        if(t & 1) odd ++;
        else even ++;
        nums.push_back(t);
        int cnt = 0;
        while(t % 2 == 0) {
            t /= 2;
            cnt ++;
        }
        ma = min(ma, cnt);
    }
    if(odd) {
        cout << even << "\n";
    } 
    else {
        cout << ma + even - 1 << "\n";
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