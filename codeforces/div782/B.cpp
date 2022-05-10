#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    string s;
    int cnt = 0;
    cin >> s;
    for(int i = 0;i < n;++i) {
        if(s[i] == '1') {
            if(k & 1) {
                if(cnt < k) {
                    cnt ++;
                    nums[i] ++;
                }
                else {
                    s[i] = '0';
                }
            }
        }
        else {
            if(!(k & 1)) {
                if(cnt < k) {
                    cnt ++;
                    nums[i] ++;
                    s[i] = '1';
                }
            }
            else {
                s[i] = '1';
            }
        }
    }
    if(cnt < k) {
        nums[n - 1] += k - cnt;
        if((k - cnt) & 1) {
            if(s[n - 1] == '1') s[n - 1] = '0';
            else s[n - 1] = '1';
        }
    }
    cout << s << "\n";
    for(int i = 0;i < n;++i) cout << nums[i] << " ";
    cout << "\n";
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