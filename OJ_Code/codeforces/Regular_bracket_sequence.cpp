#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    cin >> _;
    while(_--) {
        string s;
        cin >> s;
        if(s.size() % 2 == 1 || s[0] == ')' || s[s.size() - 1] == '(') cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}