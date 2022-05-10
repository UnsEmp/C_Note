#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> arr(N);
int main() {
    int _;
    cin >> _;
    while(_--) {
        int n;
        cin >> n;
        for(int i = 0;i < n;++i) cin >> arr[i];
        sort(arr.begin(), arr.begin() + n, greater<int>());
        for(int i = 0;i < n;++i) cout << arr[i] << " ";
        cout << "\n";
    } 
    return 0;
}
