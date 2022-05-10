#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> arr(N);

int main() {
    cin >> n;
    for(int i = 0;i < n;++i) cin >> arr[i];
    sort(arr.begin(), arr.begin() + n);
    int l = 0, r = n - 2;
    int ans = 0;
    vector<int> res;
    res.push_back(arr[n - 1]);
    while(l < r) {
        res.push_back(arr[l]);
        res.push_back(arr[r]);
        ++l;
        --r;
        ans ++;
    }
    if(l == r) res.push_back(arr[l]);
    cout << ans << "\n";
    for(int i = 0;i < res.size();++i) cout << res[i] << " ";
    return 0;
}