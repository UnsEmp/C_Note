#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n;
char ai[N], bi[N], ci[N];
int nums[N];
bool st[N];

bool check() {
    for(int i = 0;i < n;++i) {
        int a = ai[i] - 'A', b = bi[i] - 'A', c = ci[i] - 'A';
        if(nums[a] == -1 || nums[b] == -1 || nums[c] == -1) continue;
        if((nums[a] + nums[b]) % n != nums[c] && (nums[a] + nums[b] + 1) % n != nums[c]) return false;
    }
    return true;
}

bool dfs(int idx, int bit) {
    if(!check()) return false;
    if(idx == -1) {
        for(int i = 0;i < n;++i) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return true;
    }
    int a = ai[idx] - 'A', b = bi[idx] - 'A', c = ci[idx] - 'A';
    if(nums[a] == -1) {
        for(int i = n - 1;i >= 0;--i) {
            if(!st[i]) {
                st[i] = true;
                nums[a] = i;
                if(dfs(idx, bit)) return true;
                nums[a] = -1;
                st[i] = false;
            }
        }
    }
    if(nums[a] == -1) return false;
    if(nums[b] == -1) {
        for(int i = n - 1;i >= 0;--i) {
            if(!st[i]) {
                st[i] = true;
                nums[b] = i;
                if(dfs(idx, bit)) return true;
                nums[b] = -1;
                st[i] = false;
            }
        }
    }
    if(nums[b] == -1) return false;
    
    int t = (nums[a] + nums[b] + bit);
    if(nums[c] == -1) {
        
        if(!st[t % n]) {

            st[t % n] = true;
            nums[c] = t % n;
            if(nums[a] != -1 && nums[b] != -1 && nums[c] != -1 && (t) % n == nums[c] && dfs(idx - 1, t / n)) return true;
            nums[c] = -1;
            st[t % n] = false;
        }
    }
    else {
        if(t % n == nums[c] && dfs(idx - 1, t / n)) return true;
    }
    return false;
}

int main() {
    memset(nums, -1, sizeof nums);
    memset(st, 0, sizeof st);
    scanf("%d", &n);
    scanf("%s %s %s", ai, bi, ci);
    dfs(n - 1, 0);
    return 0;
}