#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 2);
    pos[n - 1] = 1;
    // sort(pos.begin(), pos.end(), greater<int>());
    // for(int i = 1;i < n;i += 2) {
    //     swap(pos[i], pos[i - 1]);
    // }
    for(int i = 0;i < n;++i)  cout << pos[i] << " ";
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