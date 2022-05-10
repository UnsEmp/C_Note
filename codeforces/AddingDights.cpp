#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll _;
    cin >> _;
    while(_--) {
        ll a, b;
        cin >> a >> b;
        if(b == 1) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        cout << a << " " << a * b << " " << a + a * b << "\n";
    }
    return 0;
}