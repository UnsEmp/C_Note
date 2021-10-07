#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    map<int, int> mp;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    // cin.ignore(numeric_limits< std::streamsize>::max());
    cin >> m;
    vector<int> brr(m);
    for(int i = 0;i < m;i++) cin >> brr[i];
    long long first = 0, end = 0;
    for(int i = 0;i < m;i++) {
        first += mp[brr[i]] + 1;
        end += n - mp[brr[i]];
    }
    cout << first << " " << end << endl;
    return 0;
}