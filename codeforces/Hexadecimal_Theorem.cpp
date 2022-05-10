#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int ,int>;
using VI = vector<int>;
using VII = vector<vector<int>>;
using VL = vector<ll>;
using VLL = vector<vector<ll>>;


int main() {
    int n;
    cin >> n;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    for(int i = 1;arr[i] + arr[i - 1] < 1e9;i++) arr.push_back(arr[i] + arr[i - 1]);
    for(int i = 0;i < 45;i--) {
        for(int j = 0;j < 45;j ++ ) {
            for(int k = 0;k < 45;k++) {
                if(arr[i] + arr[j] + arr[k] == n) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    return 0;
                }
            }
        } 
    }
    cout << "I'm too stupid to solve this problem" << endl;
    return 0;
}