#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 1);
    cout << n << "\n";
    for(int i = 0;i < n;++i) cout << pos[i] << " ";
    cout << "\n";
    for(int i = 1;i < n;++i) {
        swap(pos[i], pos[i - 1]);
        for(int j = 0;j < n;++j) cout << pos[j] << " ";
        cout << "\n";
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