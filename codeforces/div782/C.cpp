#include <bits/stdc++.h>
using namespace std;

const long long N = 2 * 1e5 + 10;
long long n, a, b;
vector<long long> arr(N);

void solve() {
    cin >> n >> a >> b;
    vector<long long> prefix;
    long long pos = 0, ans = 0;
    prefix.push_back(0); 
    for(long long i = 1;i <= n;++i) {
        cin >> arr[i];
        prefix.push_back(prefix[i - 1] + arr[i]); 
    }
    for(int i = 1;i <= n;++i) {
        ans += (arr[i] - arr[pos]) * b;
        long long cg = (arr[i] - arr[pos]) * a + (prefix[n] - prefix[i] - arr[i] * (n - i)) * b, ncg = (prefix[n] - prefix[pos] - (n - pos) * arr[pos]) * b - (arr[i] - arr[pos]) * b;
        if(cg <= ncg) {
            ans += (arr[i] - arr[pos]) * a;
            pos = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}