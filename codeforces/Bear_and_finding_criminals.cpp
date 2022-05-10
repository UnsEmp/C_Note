#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> arr(N);

int main() {
    int n, m, i;
    cin >> n >> m;
    for(i = 0;i < n;++i) cin >> arr[i];
    int ans = 0;
    for(i = 0;i + m - 1 < n && m - i - 1 >= 0;++i) {
        int l = i + m - 1, r = m - i - 1;
        if(l == r) {
            if(arr[l] == 1) ans ++;
        }
        else {
            if(arr[l] == 1 && arr[r] == 1) ans += 2;
        }  
    }
    for(;i + m - 1 < n;++i) {
        int l = i + m - 1;
        if(arr[l] == 1) ans ++;
    }
    for(;m - i - 1 >= 0;++i) {
        int r = m - i - 1;
        if(arr[r] == 1) ans ++;
    }
    cout << ans << "\n";
    return 0;
}