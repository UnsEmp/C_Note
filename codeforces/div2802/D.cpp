#include <bits/stdc++.h>

using namespace std;

const int MAX = 1007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	// assert(n != -1);
	int l = 1, r = n;
	while (l < r) {
	    int mid = (l + r) / 2;
	    cout << '?' << ' ' << l << ' ' << mid << endl;
	    int x, cnt = 0;
	    for (int i = 0; i < mid - l + 1; i++) {
	        cin >> x;
	        // assert(x != -1);
	        if (l <= x && x <= mid) {cnt++;}
	    }
	    if (cnt % 2 == 0) {l = mid + 1;}
	    else {r = mid;}
	}
	cout << '!' << ' ' << l << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}