#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> arr(n, string(n, '='));
    vector<int> p;
    for(int i = 0; i < n;++i) {
        if(s[i] == '2') 
            p.push_back(i);
    }
    if(p.size() > 2 || p.size() == 0) {
        cout << "YES" << "\n";
        for(int i = 0;i < n;++i) arr[i][i] = 'X';
        for(int i = 0;i < p.size();++i) {
            int x = p[i], y = p[(i + 1) % (int)(p.size())];
            arr[x][y] = '+';
            arr[y][x] = '-';
        }
        for(int i = 0;i < n;++i) { 
            for(int j = 0;j < n;++j) 
                cout << arr[i][j];
            cout << "\n";
        }

    }
    else {
        cout << "NO" <<"\n";
    }

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