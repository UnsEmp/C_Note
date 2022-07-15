#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    vector<int> pa, ne, ze;
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        mp[nums[i]] ++;
        if(nums[i] > 0) pa.push_back(nums[i]);
        else if(nums[i] < 0) ne.push_back(nums[i]);
        else {
            if(ze.size() < 2)
            ze.push_back(nums[i]);
        }
    }
    if(pa.size() > 2 || ne.size() > 2) {
        cout << "NO" << "\n";
        return ;
    }
    vector<int> a(pa.begin(), pa.end());
    for(int i = 0;i < ne.size();++i) a.push_back(ne[i]);
    for(int i = 0;i < ze.size();++i) a.push_back(ze[i]);
    for(int i = 0;i < a.size();++i) {
        for(int j = i + 1;j < a.size();++j) {
            for(int k = j + 1;k < a.size();++k) {
                int t = a[i] + a[j] + a[k];
                if(!mp[t]) {
                    cout << "NO" << "\n";
                    return ;
                }
            }
        }
    }
    cout << "YES" << "\n";
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