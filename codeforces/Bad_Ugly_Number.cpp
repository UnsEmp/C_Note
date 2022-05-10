#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int _;
    cin >> _;
    while(_--) {
        int n;
        string s = "2";
        cin >> n;
        if(n == 1) {
            cout << "-1" << "\n";
            continue;
        }
        else {
            // string s = "2";
            for(int i = 1;i < n;++i) s += '0' + 3; 
        }
        cout << s << "\n";
    }
    return 0;
}