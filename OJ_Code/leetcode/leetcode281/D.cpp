#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 450;
ll n, k, p;
bool flag = false;
vector<pair<ll, ll>> arr(N), ans(N);

void dfs(ll idx, ll sum, ll bo, ll ex) {
        if(idx == k) {
                if(sum != n) return ;
                flag = true;
                for(ll i = 0;i < k;i++) {
                        ans[i].first = arr[i].first;
                        ans[i].second = arr[i].second;
                }
                return ;
        }
        if(idx > k) return ;
        if(sum >= n) return ;
        if(((ll)pow(bo, ex) * (k - idx) + sum) > n) return ;
        arr[idx].first = bo;
        arr[idx].second = ex;
        dfs(idx + 1, sum + (ll)pow(bo, ex), bo, ex);
        dfs(idx, sum, bo + 1, ex);
}


int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> k >> p;
        dfs(0, 0, 1, p);
        if(flag) {
            cout << n << " = ";
            for(ll i = k - 1;i >= 0;--i) {
                    cout << ans[i].first << "^" << ans[i].second;
                    if(i != 0) cout << " + ";
            }
            cout << endl;
        }
        else cout << "Impossible" << endl;
        return 0;
}