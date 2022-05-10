#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool flag = false;
    int i = 30;
    while((n >> i) == 0) --i;
    for(;i >= 0;--i) {
        if((n >> i) & 1) {
            if(flag == false) flag = true;
            else {
                cout << "0" << "\n";
                return 0;
            }
        }  
        else {
            if(flag == true) flag = false;
            else {
                cout << "0" << "\n";
                return 0;
            }
        }
    }
    cout << "1" << "\n";
    return 0;
}