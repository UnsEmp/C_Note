#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> arr(N);

bool check(int a,int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i < n;++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);
    for(int i = 1;i < n - 1;++i) {
        if(check(arr[i - 1], arr[i], arr[i + 1])) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}