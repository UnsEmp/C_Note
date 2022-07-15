#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int se, a, b, c, d;
    cin >> se >> a >> b >> c >> d;
    int n;
    cin >> n;
    for(int i = 0;i < n;++i) {
        int sex, l, r;
        cin >> sex >> l >> r;
        if(se != sex && (l >= a && l <= b) && (r >= c && r <= d)) cout << sex << " " << l << " " << r << "\n";       
    }
    return 0;
}