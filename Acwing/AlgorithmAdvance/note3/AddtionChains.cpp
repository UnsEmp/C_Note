#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, ans;
int nums[N], arr[N];
void dfs(int idx, int dep) {
    if(idx == dep) {
        if(nums[idx - 1] == n) {
            ans = idx;
            for(int i = 0;i <= idx;++i) {
                arr[i] = nums[i];
            }
        }
        return ;
    }
    bool st[110] = {0};
    for(int i = idx - 1;i >= 0;--i) {
        for(int j = i;j >= 0;--j) {
            int t = nums[i] + nums[j];
            if(st[t] || t > n || t <= nums[idx - 1]) continue;
            st[t] = true;
            nums[idx] = t;
            dfs(idx + 1, dep);
            if(ans != 110) return ;
        }
    }
}

int main() {
    while((cin >> n) && n) {
        ans = 110;
        nums[0] = 1;
        for(int i = 1;i <= 10;++i) {
            dfs(1, i);
            if(ans != 110) break;
        }
        for(int i = 0;i < ans;++i) {
            cout << arr[i] << " \n"[i == ans - 1];
        }
    }
    return 0;
}