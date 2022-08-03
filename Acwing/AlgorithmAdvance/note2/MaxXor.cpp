#include <bits/stdc++.h>
using namespace std;
const int N = 4e6;
int son[N][2], idx = 0;

void insert(int x) {
    int p = 0;
    for(int i = 30;i >= 0;--i) {
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int sum = 0, p = 0;
    for(int i = 30;i >= 0;--i) {
        int u = (x >> i) & 1;
        if(son[p][!u]) sum += (1 << i), p = son[p][!u];
        else p = son[p][u];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    memset(son, 0, sizeof son);
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        insert(nums[i]);
    }
    int ans = INT_MIN;
    for(int i = 0;i < n;++i) {
        ans = max(ans, query(nums[i]));
    }
    cout << ans << "\n";
    return 0;
}