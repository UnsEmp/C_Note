#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;++i) cin >> a[i];
    cin >> m;
    int top = 0;
    while(m--) {
        int t;
        cin >> t;
        top = (top + t) % n;
    }    
    cout << a[top] << "\n";
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
