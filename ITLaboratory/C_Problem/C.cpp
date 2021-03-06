#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        int n, k;
        cin >> n >> k;
        vector<long long> arr;
        for(int i = 0;i < k;i++) {
            int tmp;
            cin >> tmp;
            arr.push_back(n - tmp);
        }
        // sort(arr.begin(), arr.end());
        for(int i = arr.size() - 1;i > 0;i--) {
            for(int j = 1;j <= i;j++) {
                if(arr[j - 1] > arr[j]) {
                    int tmp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        for(int i = 1;i < k;i++) {
            arr[i] += arr[i - 1];
        }
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(arr[mid] >= n - 1) r = mid;
            else l = mid + 1;
        }
        if(l < arr.size() && arr[l] <= n - 1) cout << l + 1 << endl;
        else cout << l << endl;
    }
    return 0;
}