#include <bits/stdc++.h>
using namespace std;
int n;
map<int, set<int>> grid;
map<int, int> mp;
int bfs(int x) {
    int ans = 1;
    queue<int> q;
    q.push(x);
    if(!mp[x])
    mp[x] ++;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto m : grid[t]) {
            if(!mp[m]) {
                mp[m] ++;
                ans ++;
                q.push(m);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    set<int> p;
    for(int i = 1;i <= n;++i) cin >> arr[i];
    for(int i = 1;i <= n;++i) {
        for(int j = i + 1;j <= n;++j) {
            if(arr[i] > arr[j]) {
                grid[i].insert(j);
                grid[j].insert(i);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;++i) {
        ans = max(ans, bfs(i));
    }
    cout << ans << "\n";
    return 0;
}