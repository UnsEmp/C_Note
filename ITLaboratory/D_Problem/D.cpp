#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while( _-- ) {
        int n;
        cin >> n;
        int tmp = 0, count = 0, size = 0;
        for(int i = 1;i <= n;i++) {
            cin >> tmp;
            while(tmp > size + 1) {
                count++;
                size++;
            }
            size++;
        }
        cout << count << endl;
    }
}