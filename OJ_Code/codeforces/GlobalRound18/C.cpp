#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int prefix[32][N];

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int zo = 0, oz = 0;
    bool
    for(int i = 0;i < n;++i) {
        if(s1[i] == '0' && s2[i] == '1') zo ++;
        else if(s1[i] == '1' && s2[i] == '0') oz ++;
    }
    
    // if(zo == oz) {
    //     if(zo & 1) cout << zo << "\n";
    //     else cout << zo + oz << "\n";
    // }
    // else cout << "-1" << "\n";
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