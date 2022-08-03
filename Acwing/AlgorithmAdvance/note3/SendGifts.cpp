#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int nums[N];
int arr[1 << 24];
int w, n, cnt = 0;
int ans = 0;

void dfs1(int idx, int sum) {
    if(idx == n / 2) {
        arr[cnt++] = sum;
        ans = max(ans, (int)sum);
        return ;
    }
    if((long long)sum + nums[idx] <= w)dfs1(idx + 1, sum + nums[idx]);
    dfs1(idx + 1, sum);
}

void dfs2(int idx, int sum) {
    if(idx == n) {
        auto t = upper_bound(arr, arr + cnt, w - sum) - arr - 1;
        ans = max(ans, arr[t] + sum);
        return ;
    }
    if((long long)sum + nums[idx] <= w) dfs2(idx + 1, sum + nums[idx]);
    dfs2(idx + 1, sum);
}

signed main() {
    cin >> w >> n;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n, greater<int>());
    dfs1(0, 0);
    sort(arr, arr + cnt);
    int t = 0;
    for(int i = 1;i < cnt;++i) {
        if(arr[t] != arr[i]) arr[++t] = arr[i];
    }
    cnt = t + 1;
    dfs2(n / 2, 0);
    cout << ans << "\n";
    return 0;
}