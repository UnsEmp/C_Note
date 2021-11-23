#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int count = 0;
    unordered_map<int, int> mp;
    for(int i = k;i <= d;i += k) {
        mp[i]++;
    }
    for(int i = l;i <= d;i += l) {
        mp[i]++;
    }
    for(int i = m;i <= d;i += m) {
        mp[i]++;
    }
    for(int i = n;i <= d;i += n) {
        mp[i]++;
    }
    for(int i = 1;i <= d;i++) {
        if(mp[i])
            count++;
    }
    cout << count << endl;
    return 0;
}