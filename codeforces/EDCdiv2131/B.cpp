#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int prefix[32][N];

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    cout << "2" << "\n";
    for(int i = 1;i <= n;++i) {
        if(!mp[i]) {
            for(int j = i;j <= n;j *= 2) {
                if(!mp[j]) {
                    mp[j] ++;
                    cout << j << " ";
                }
                else {
                    break;
                }
            }
        }
    }
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