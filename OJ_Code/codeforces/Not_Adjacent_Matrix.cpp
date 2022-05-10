#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a;i <= b;++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "1" << "\n";
        }
        else if(n == 2) {
            cout << "-1" << "\n";
        }
        else {
            int x = 1, y = 2;
            rep(i, 0, n - 1){
                rep(j, 0, n - 1) {
                    if(x <= n * n) {
                        cout << x << " ";
                        x += 2;
                    }
                    else {
                        cout << y << " ";
                        y += 2;
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}