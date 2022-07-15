#include <bits/stdc++.h>
using namespace std;


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= m;++i) {
        if(i % 2 == 0) continue;
        for(int j = i + 1;j <= m;++j) {
            if(j % 2 == 0) continue;
            for(int k = j + 1;k <= m;++k) {
                if(k % 2 == 0) continue;
                if((i * j + j * k + k * i) * n == 3 * i * j * k) {
                    cout << i << " " << j << " " << k << "\n";
                    return 0;
                }
            }
        }
    }
    printf("No solution in (3, %d].\n", m);
    return 0;
}