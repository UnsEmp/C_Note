#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p;
    string s;
    cin >> s >> p;
    int ha[27];
    memset(ha, 0, sizeof ha);
    int sum = 0;
    for(int i = 0;i < s.size();++i) {
        int u = s[i] - 'a';
        sum += u + 1;
        ++ ha[u];
    }
    while(sum > p) {
        for(int i = 25;i >= 0;--i) {
            int t = ha[i], num = i + 1;
            if(sum - t * num > p) {
                ha[i] = 0;
                sum -= t * num;
            }
            else {
                int j;
                for(j = 1;j <= t;++j) {
                    if(sum - j * num <= p) {
                        ha[i] -= j;
                        sum -= j * num;
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int i = 0;i < s.size();++i) {
        int u = s[i] - 'a';
        if(ha[u] > 0) {
            cout << s[i];
            -- ha[u];
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