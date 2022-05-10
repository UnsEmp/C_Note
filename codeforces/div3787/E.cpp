#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;
    vector<int> nums;
    for(int i = 0;i < m;++i) {
        int t;
        cin >> t;
        if(mi.empty() || t >= mi.top()) mi.push(t);
        else ma.push(t);
        if(i & 1) {
            if(ma.size() > mi.size()) {
                mi.push(ma.top());
                ma.pop();
            }
            if(ma.size() < mi.size()) {
                ma.push(mi.top());
                mi.pop();
            }
        }
        else {
            if(ma.size() >= mi.size()) {
                mi.push(ma.top());
                ma.pop();
            }
            nums.push_back(mi.top());
        }
    }
    cout << n << " " << nums.size() << "\n";
    for(int i = 0;i < nums.size();++i) cout << nums[i] << " ";
    cout << "\n";
}

int main() {
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}