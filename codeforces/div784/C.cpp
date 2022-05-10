#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    bool f1 = true, f2 = true;
    for(int i = 0;i < n;++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    for(int i = 2;i < n;i += 2) {
        if((arr[i] & 1) != (arr[i - 2] & 1)) {
            f1 = false;
            break;
        }
    }
    for(int i = 3;i < n;i += 2) {
        if((arr[i] & 1) != (arr[i - 2] & 1)) {
            f2 = false;
            break;
        }
    }
    if(f1 && f2) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
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