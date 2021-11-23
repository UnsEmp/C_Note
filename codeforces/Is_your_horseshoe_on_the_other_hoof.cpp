#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp;
    int tmp, count = 0;
    for(int i = 0;i < 4;i++) {
        cin >> tmp;
        if(!mp[tmp]) {
            count++;
            mp[tmp]++;
        }
    }
    cout << 4 - count << endl;
    return 0;
}