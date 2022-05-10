#include <bits/stdc++.h>
using namespace std;

int n, k, t;
vector<int> arr;

bool check(int x) {
    int count = 0;
    for(int i = 0;i < n;++i) count += arr[i] / x;
    return count >= k?true:false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    while(cin >> t) {
        arr.push_back(t);
    }
    // for(int i = 0;i < n;++i) {
    //     cin >> t;
    //     arr.push_back(t);
    // }
    n = arr.size();
    int l = 0, r = 1e7;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
    return 0;
}