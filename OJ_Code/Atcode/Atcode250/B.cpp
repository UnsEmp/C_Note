#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
int n, a, b, m;
vector<vector<char>> grid(N, vector<char>(N, '.'));

// void fun(int x, int y) {
//     for(int i = 1;i <= n;++i) {
//         for(int j = 1;j <= n;++j) {
//             if(abs(x - i) + abs(y - j) == 1) {
//                 if(grid[i][j] == grid[x][y]) {
//                     if(grid[i][j] == '.') grid[i][j] = '#';
//                     else grid[i][j] = '.';
//                 }
//             }
//         }
//     }
// }

int main() {
    cin >> n >> a >> b;
    int cnt = 0;
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= n;++j) {
            int x = a * i, y = j * b;
            for(int k = x - a + 1;k <= x;++k) {
                for(int t = y - b + 1;t <= y;++t) {
                    if(cnt % 2 == 0) grid[k][t] = '.';
                    else grid[k][t] = '#';
                }
            }
            // if(n % 2 == 0) cnt ++;
            cnt ++;
        }
        if(n % 2 == 0) cnt ++;
    }
    // n = n * a, m = b * n;
    // for(int i = 1;i <= n;++i) {
    //     for(int j = 1;j <= m;++j) {
    //         fun(i, j);
    //     }
    // }
    for(int i = 1;i <= n * a;++i) {
        for(int j = 1;j <= n * b;++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}