#include <bits/stdc++.h>
using namespace std;

bool check(string & s, int cnt, int k) {
    int w = 0;
    int n = s.size();
    int i = 0, j = 0;
    for(i = 0;i < n;++i) {
        while(j < n) {
            if(s[j] == 'W') {
                if(w >= cnt) break;
                else w++;
            }  
            j ++;
        }
        if(j - i >= k) return true;
        if(s[i] == 'W') w--;

    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = k;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(s, mid, k)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
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