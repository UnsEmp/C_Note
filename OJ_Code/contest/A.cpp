#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1e5;
const int eps = 1100;
int q[N], t = -1, w = 0;

int f[110][110], arr[110][110];

void solve() {
    int n, m;
    // scanf("%d %d", &n, &m);
    cin >> n >> m;
    f[1][1] = 1;
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) f[i][j] += (f[i - 1][j] + f[i][j - 1]) % 12345678;
            else f[i][j] = 0;
        }
    }
    // for(int i = 1;i <= n;++i) {
    //     for(int j = 1;j <= m;++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 1)
    cout << f[n][m] << "\n";
}

int main() {
    solve();
    return 0;
}

