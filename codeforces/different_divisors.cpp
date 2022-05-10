#include <bits/stdc++.h>
using namespace std;


bool check(int n) {
    for(int i = 2;i * i <= n;++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    vector<int> arr;
    for(int i = 2;i < 21000;++i) {
        if(check(i)) arr.push_back(i);
    }
    while(_--) {
        int d, ans = 1, bit = 1;
        cin >> d;
        auto t1 = lower_bound(arr.begin(), arr.end(), 1 + d) - arr.begin();
        auto t2 = lower_bound(arr.begin(), arr.end(), arr[t1] + d) - arr.begin();
        cout << arr[t1] * arr[t2] << "\n";
    }
    return 0;
}