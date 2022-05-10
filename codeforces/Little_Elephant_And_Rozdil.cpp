#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int,int> mp, sign;
    int n, tmp, Min = INT_MAX;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> tmp;
        mp[tmp] ++;
        sign[tmp] = i;
        Min = min(Min, tmp);
    }
    if(mp[Min] > 1) cout << "Still Rozdil" << endl;
    else cout << sign[Min] + 1 << endl;
    return 0;
}