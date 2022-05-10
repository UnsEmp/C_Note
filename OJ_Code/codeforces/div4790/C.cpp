#include <bits/stdc++.h>
using namespace std;

int cal(string s1, string s2) {
    int sum = 0;
    for(int i = 0;i < s1.size();++i) {
        sum += abs(s1[i] - s2[i]);
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr;
    string s;
    int ans = INT_MAX;
    for(int i = 0;i < n;++i) {
        cin >> s;
        arr.push_back(s);
    }
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < n;++j) {
            if(i == j) continue;
            ans = min(ans, cal(arr[i], arr[j]));
        }
    }
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}