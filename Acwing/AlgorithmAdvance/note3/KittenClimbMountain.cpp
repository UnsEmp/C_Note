#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
long long n, m;
int ans;
long long cat[N], cab[N];
void dfs(int now, int cnt) {
    if(cnt >= ans) return ;
    if(now == n) {
        ans = min(ans, cnt + 1);
        return ;
    }
    for(int i = 0;i <= cnt;++i) {
        if(cat[now] + cab[i] <= m) {
            cab[i] += cat[now];
            dfs(now + 1, cnt);
            cab[i] -= cat[now];
        } 
    }
    cab[cnt + 1] = cat[now];
    dfs(now + 1, cnt + 1);
    cab[cnt + 1] = 0;

}

int main() {
    memset(cat, 0, sizeof cat);
    memset(cab, 0, sizeof cab);
    cin >> n >> m;
    ans = n;
    for(int i = 0;i < n;++i) cin >> cat[i];
    sort(cat, cat + n, greater<int>());
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}