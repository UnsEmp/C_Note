#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int nums[N];
int tree[N];

int lowerbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for(;k <= n;k += lowerbit(k)) {
        tree[k] += x;
    }
}

int ask(int k) {
    int sum = 0;
    for(;k > 0;k -= lowerbit(k)) {
        sum += tree[k];
    }
    return sum;
}

void solve() {
    cin >> n;
    memset(tree, 0, sizeof tree);
    int ans = 0;
    for(int i = 1;i <= n;++i) {
        cin >> nums[i];
        ans += (ask(n) - ask(nums[i] - 1));
        add(nums[i], 1);
    }
    cout << ans << "\n";
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