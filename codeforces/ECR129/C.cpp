#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int k = 0;
    vector<int> a(n), b(n);
    vector<pair<int,int>> arr;
    for(int i = 0;i < n;++i) cin >> a[i];
    for(int i = 0;i < n;++i) cin >> b[i];
    for(int i = 0;i < n;++i) {
        for(int j = i + 1;j < n;++j) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                arr.push_back({j, i});
                k ++;
            }
        }
    }
    bool flag = true;
    for(int i = 0;i < n;++i) {
        for(int j = i + 1;j < n;++j) {
            if(b[i] > b[j]) {
                if(a[i] == a[j]) {
                    k ++;
                    swap(b[i], b[j]);
                    arr.push_back({j, i});
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    if(flag) {
        cout << k << "\n";
        for(int i = 0;i < arr.size();++i) cout << arr[i].first + 1 << " " << arr[i].second + 1 << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
}
