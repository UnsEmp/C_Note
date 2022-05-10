#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6;

// vector<int> primes;

int primes[6000010], cnt = 0;

bitset<maxn + 1> st;

auto sieve = []() {
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        // primes.push_back(i);
        primes[cnt++] = i;
    }
    return nullptr;
} ();

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << primes[x - 1] << '\n';
    }
    return 0;
}