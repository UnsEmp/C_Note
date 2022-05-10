#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int main() {
    vector<vector<char>> arr(N, vector<char>(N, ' '));
    int n;
    cin >> n;
    for(int row = -n; row <= n;++row) {
        int t = n - abs(row);
        for(int i = 0;i < abs(row);++i) cout << "  ";
        for(int i = 0;i < t;++i) cout << i << " ";
        for(int j = t;j > 0;--j) cout << j << " ";
        cout << "0" << "\n";
    }
    return 0;
}