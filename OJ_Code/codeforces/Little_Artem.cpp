#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    cin >> _;
    while(_--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                if(i == 0 && j == 0) cout << "W";
                else cout << "B";  
            }
            cout << "\n";
        }
    }
    return 0;
}