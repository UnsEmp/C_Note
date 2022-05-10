#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n;

int f(int n) {
    if(n == 1 || n == 0) return 1;
    return (n * f(n - 1)) % mod;
}

int comb(int a, int b) {
    cout << a << " " << b << endl;
    b = min(a - b, b);
    return f(a) / (f(a - b) * f(b));
}

int main() {
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << comb(a, b) << endl;
    }
    return 0;
}