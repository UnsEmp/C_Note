#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int Drink = k * l / nl;
    int lime = c * d;
    int salt = p / np;
    int tmp = min(Drink, lime);
    tmp = min(tmp, salt);
    cout << tmp / n << endl;
    return 0;
}