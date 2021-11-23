#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        int a, b, c;
        cin >> a >> b >> c;
        if((a + b + c) % 3 == 2 || (a + b + c) % 3 == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}