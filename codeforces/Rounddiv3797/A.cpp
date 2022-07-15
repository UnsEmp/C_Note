#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mid = n / 3, bit = n % 3;
    if(bit == 2) cout << mid + 1 << " " << mid + bit << " " << mid - 1 << "\n";
    else if(bit == 0) cout << mid << " " << mid + 1 << " " << mid - 1 << "\n";
    else cout << mid << " " << mid + 2 << " " << mid - 1 << "\n";
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