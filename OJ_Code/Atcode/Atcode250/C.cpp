#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, q;
const int N = 2e5 + 10;
vector<int> nums(N), arr(N);
unordered_map<int, int> idx;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 1;i <= n;++i) {
        arr[i] = i;
        idx[i] = i;
    }
    for(int i = 1;i <= q;++i) {
        cin >> nums[i];
    }
    for(int i = 1;i <= q;++i) {
        if(idx[nums[i]] < n) {
            int l = idx[nums[i]], r = idx[nums[i]] + 1;
            swap(arr[l], arr[r]);
            swap(idx[arr[l]], idx[arr[r]]);
        }
        else {
            int l = idx[nums[i]] - 1, r = idx[nums[i]];
            swap(arr[l], arr[r]);
            swap(idx[arr[l]], idx[arr[r]]);
        }
    }
    for(int i = 1;i <= n;++i) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}