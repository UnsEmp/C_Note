#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 15;
int dp[N], pre[N], word[N];
vector<string> arr(M);


void solve() {
    memset(dp, 0x3f, sizeof dp);
    memset(pre, -1, sizeof pre);
    string t;
    cin >> t;
    int n;
    cin >> n;
    for(int i = 0;i < n;++i) cin >> arr[i];
    dp[0] = 0;
    for(int i = 0;i < t.size();++i) {
        for(int j = 0;j < n;++j) {
            string s = arr[j];
            int len = s.size();
            if(t.substr(i, len) == s) {
                for(int k = 1;k <= len;++k) {
                    if(dp[i + k] > dp[i] + 1) {
                        dp[i + k] = dp[i] + 1;
                        pre[i + k] = i;
                        word[i + k] = j + 1; 
                    }
                }
            }
        }
    }
    if(dp[t.size()] == 0x3f3f3f3f) {
        cout << "-1" << "\n";
        return ;
    }

    vector<pair<int, int>> ans;
    int sta = t.size();
    while(pre[sta] != -1) {
        ans.push_back({word[sta], pre[sta] + 1});
        sta = pre[sta];
    }
    cout << dp[t.size()] << "\n";
    for(int i = 0;i < ans.size();++i) cout << ans[i].first << " " << ans[i].second << "\n";
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