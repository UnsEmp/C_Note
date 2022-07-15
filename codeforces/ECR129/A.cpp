#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;++i) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0;i < m;++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[n - 1] == b[m - 1]) {
        cout << "Alice" << "\n";
        cout << "Bob" << "\n";
    }
    else {
        if(a[n - 1] > b[m - 1]) {
            cout << "Alice" << "\n";
            cout << "Alice" << "\n";
        }
        else {
            cout << "Bob" << "\n";
            cout << "Bob" << "\n";
        }
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
}
