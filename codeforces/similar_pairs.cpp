#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

bool isprime(int n) {
    if(n == 1) return false;
    for(int i = 2;i <= n / i;++i)
        if(n % i == 0) return false; 
    return true;
} 

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    stack<int> st;
    int even = 0, odd = 0;
    for(int i = 1;i < arr.size();i += 2) {
        if(arr[i - 1] + 1 == arr[i]) {
            st.push(arr[i]);
            st.push(arr[i - 1]);
        }
        else {
            if(arr[i] & 1) odd ++;
            else even ++;
            if(arr[i - 1] & 1) odd ++;
            else even ++;
        }
    }
    if(st.size() % 2 == 0 && odd % 2 == 0 && even % 2 == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) 
        solve();
    return 0;
}
