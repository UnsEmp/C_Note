#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for(int i = 1;i <= a;++i) {
        for(int j = 1;j <= b;++j) {
            if(abs(i - c) + abs(j - d) == 1) ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}