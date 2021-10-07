#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    int count = 0;
    cin >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        count += (a + b + c) >= 2?1:0;
    }
    cout << count << endl;
    return 0;
}