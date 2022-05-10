#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<string> arr;
    cin >> n;
    for(int i = 1;i <= n;++i) arr.push_back(to_string(i));
    sort(arr.begin(), arr.end());
    for(int i = 0;i < arr.size();++i) cout << arr[i] << "\n";
    return 0;
}
