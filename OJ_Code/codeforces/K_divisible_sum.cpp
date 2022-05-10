#include <bits/stdc++.h>
using namespace std;

int main() {
        int _;
        cin >> _;
        while(_--) {
                int n, k;
                cin >> n >> k;
                int ans = 0;
                if(n > k) {
                        ans = n;
                        if(n % k)
                            ans = (n / k + 1) * k;
                        if(ans % n) ans = ans / n + 1;
                        else ans = ans / n; 
                }
                else if(n < k) {
                        ans = k / n;
                        if(k % n) ans ++;
                }
                else ans = 1;
                cout << ans << "\n";
        }
        return 0;
}