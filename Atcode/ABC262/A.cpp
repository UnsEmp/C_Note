#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    // int t = (n % 4) - 2;
    // if(t > 0) cout << n
    if(n % 4 == 1)  cout << n + 1 << "\n";
    else if(n % 4 == 2) cout << n << "\n";
    else if(n % 4 == 3) cout << n + 3 << "\n";
    else {
        cout << n + 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int _;
    // cin >> _;
    // while(_--) {
        solve();
    // }
    return 0;
}