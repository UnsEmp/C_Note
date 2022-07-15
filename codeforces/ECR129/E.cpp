#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
int arr[N];
int t = 30;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    memset(arr, 0 ,sizeof arr);
    for(int i = 0;i < n;++i) {
        arr[i] = s[i] - 'a' + 1;
    }
    int ans = 0;
    for(int i = 0;i < n;++i) {
        if(arr[i] == arr[i + 2]) {
            if(i && arr[i] == arr[i - 1]) arr[i] = t++, ans ++;
            else arr[i + 2] = t++, ans ++;
        } 
    }
    for(int i = 0;i < n;++i) {
        if(arr[i] == arr[i + 1]) {
            arr[i + 1] = t++;
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}