#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;


    int l = 0, r = n - 1;
    while(l + 1 < n && s[l] != '1') l ++;
    while(r - 1 >= 0 && s[r] != '1') r --;
    int cnt = 0;
    for(int i = 0;i < s.size();++i) {
        if(s[i] == '1') cnt ++;
    }
    if(cnt <= 1) {
        
    }
    else {
        if(r >= 0 && r <= n - 1 && (n - r - 1) <= k) {
            k -= (n - 1 - r);
            swap(s[n - 1], s[r]);
        }
        if(l >= 0 && l <= n - 1 && l <= k) {
            k -= l;
            swap(s[0], s[l]);
        }
    }

    for(int i = 1;i < s.size();++i) {
        int a = s[i - 1] - '0', b = s[i] - '0';
        ans += (a * 10 + b);
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