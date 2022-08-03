#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) cin >> nums[i];
    // vector<set<int>> div;
    set<int> st;
    // st.insert(nums[0]);
    // div.push_back(st);
    st.insert(nums[0]);
    if(nums[0] == 1) {
        cout << "YES" << "\n";
        return ;
    }
    for(int i = 1;i < n;++i) {
        bool flag = false;
        for(auto & j : st) {
            if(nums[i] % j == 0) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "NO" << "\n";
            return ;
        }
    } 
    cout << "YES" << "\n";
    // for(int i = 1;i < n;++i) {
    //     // bool flag = true;
    //     for(auto & j : div[i]) {
    //         if(div[i - 1].find(j) == div[i - 1].end()) {
    //             cout << "NO" << "\n";
    //             return ;
    //         }
    //     }
    // }
    // cout << "YES" << "\n";
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