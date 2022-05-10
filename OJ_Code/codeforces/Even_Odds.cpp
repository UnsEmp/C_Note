#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int,int>;

int main() {
    ll n, k;
    cin >> n >> k;
    if(n % 2 == 0) {
        if(k <= n / 2) {
            cout << k + (k - 1) << endl;
        }
        else {
            cout << 2 * k - n << endl;
        }
    }
    else {
        if(k <= n / 2 + 1) {
            cout << k + (k - 1) << endl;
        }
        else {
            cout << 2 * k - n - 1 << endl;
        }
    }
    return 0;
}