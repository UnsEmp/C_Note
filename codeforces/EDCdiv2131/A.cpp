#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int prefix[32][N];

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a && b && c && d) {
        cout << "2" << "\n";
    }
    else if(a || b || c || d){
        cout << "1" << "\n";
    }
    else {
        cout << "0" << "\n";
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