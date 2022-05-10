#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    cin >> _;
    while(_--) {
        int n, sum = 0;
        cin >> n;
        for(int i = 0;i < n;i++) {
            int tmp;
            cin >> tmp;
            sum = (sum + tmp) % n;
        }
        if(sum) cout << 1 << endl;
        else cout << 0 << endl;
    }
}