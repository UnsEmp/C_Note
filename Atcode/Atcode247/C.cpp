#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string ans = "1";
    for(int i = 2;i <= n;++i) {
        ans = ans + " " + to_string(i) + " " + ans;
    }
    cout << ans << "\n";
    // int len = ans.size();
    // for(int i = 0;i < len;++i) {
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    return 0;
}























