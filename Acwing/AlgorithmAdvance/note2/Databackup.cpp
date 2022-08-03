#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
LL l[N], r[N], d[N];

void del_node(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

int main() {
    LL n, k;
    cin >> n >> k;
    vector<LL> nums(n);
    priority_queue<pair<LL,int>, vector<pair<LL, int>>, greater<pair<LL, int>>> heap;
    for(int i = 0;i < n;++i) cin >> nums[i];
    for(int i = n - 1;i > 0;--i) d[i] = nums[i] - nums[i - 1]; 
    d[0] = d[n] = 1e15;
    for(int i = 0;i <= n;++i) {
        l[i] = i + 1;
        r[i] = i - 1;
        heap.push({d[i], i});
    }
    LL ans = 0;
    map<int, int> mp;
    while(k --) {
        while(heap.size() && mp[heap.top().second]) heap.pop();
        auto t = heap.top();
        heap.pop();
        int v = t.first, m = t.second;
        // cout << v << " " << m << "\n";
        ans += v;
        d[m] = d[l[m]] + d[r[m]] - d[m];
        mp[l[m]] ++, mp[r[m]] ++;
        del_node(l[m]), del_node(r[m]);
        heap.push({d[m] ,m});
    }
    cout << ans << "\n";
    return 0;
}