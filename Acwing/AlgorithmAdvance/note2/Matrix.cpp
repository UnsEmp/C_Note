#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull pp = 13331;
const int N = 1010;
int n, m, a, b;
ull ha[N][N], p[N];

inline void init() {
    memset(p, 0, sizeof p);
    memset(ha, 0, sizeof ha);
    p[0] = 1;
}

inline ull get(int i, int l, int r) {
    return ha[i][r] - ha[i][l - 1] * p[r - l + 1];
}


int main() {
    init();
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int nums[n][m], arr[a][b];
    map<ull, bool> mp;
    getchar();
    for(int i = 1;i <= m;++i) {
        p[i] = p[i - 1] * pp;
    }
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            char ch = getchar();
            nums[i][j] = ch - '0';
            ha[i][j + 1] = ha[i][j] * pp + nums[i][j];
        }
        getchar();
    }    
    for(int i = 0;i <= n - a;++i) {
        for(int j = 0;j <= m - b;++j) {
            ull sum = 0;
            for(int t = i;t < i + a;++t) {
                sum = sum * 131 + get(t, j + 1, j + b);
            }
            mp[sum] = true;
        }
    }
    int q, ans = 0;
    scanf("%d", &q);
    getchar();
    while(q--) {
        ull sum = 0;
        for(int i = 0;i < a;++i) {
            ull h = 0;
            for(int j = 0;j < b;++j) {
                char ch = getchar();
                arr[i][j] = ch - '0'; 
                h = h * pp + arr[i][j];
            }
            sum = sum * 131 + h;
            getchar();
        }
        if(mp[sum]) printf("1\n");
        else printf("0\n");
    }

    return 0;
}