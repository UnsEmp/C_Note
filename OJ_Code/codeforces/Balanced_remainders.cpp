#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        cin >> n;
        int tmp;
        vector<int> a(3);
        for(int i = 0;i < n;++i) {
            cin >> tmp;
            a[tmp % 3] ++;
        }
        int ans = 0;
        int t = 0;
        while(!(a[0] == a[1] && a[1] == a[2])) {
            if(a[t] > n / 3) {
                int j = (t + 1) % 3;
                ans += a[t] - n / 3;
                a[j] += a[t] - n / 3;
                a[t] = n / 3;
            }
            t = (t + 1) % 3;
        }
        cout << ans << "\n"; 
    }
    return 0;
}