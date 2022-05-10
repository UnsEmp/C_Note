// 区间修改， 单点查询
#include <bits/stdc++.h>
using namespace std;
typedef long long int;

const int N = 1e6;
int n, m;
vector<int> arr(N), Tree(N);

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for(;k <= n;k += lowbit(k)) Tree[k] += x; 
}

int ask(int k) {
    int ans = 0;
    for(;k;k -= lowbit(k)) ans += Tree[k]; 
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> arr[i];
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -1 * k); 
        }
        else {
            int x;
            cin >> x;
            cout << arr[x] + ask(x) << "\n";
        }
    }
    return 0;
}