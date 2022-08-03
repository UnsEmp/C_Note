#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 100;
int n, ma, tot, len;
int nums[N];
bool st[N];

bool dfs(int idx, int sum, int last) {
    if(idx >= tot / len) return true;
    if(sum == len) {
        return dfs(idx + 1, 0, 0);
    }
    int fail = 0;
    for(int i = last;i < n;++i) {
        if(!st[i] && sum + nums[i] <= len && fail != nums[i]) {
            st[i] = true;
            if(dfs(idx, sum + nums[i], i + 1)) return true;
            fail = nums[i];
            st[i] = false;
            if(sum == 0 || sum + nums[i] == len) return false;
        }
    }
    return false;
}


int main() {
    while(cin >> n && n) {
        ma = 0, tot = 0;
        memset(st, 0, sizeof st);
        for(int i = 0;i < n;++i) {
            cin >> nums[i];
            ma = max(ma, nums[i]);
            tot += nums[i];
        }
        sort(nums, nums + n, greater<int>());
        for(int i = ma;i <= tot;++i) {
            if(tot % i) continue;
            len = i;
            if(dfs(0, 0, 0)) {
                cout << i << "\n";
                break;
            }
        } 
    }
    return 0;
}