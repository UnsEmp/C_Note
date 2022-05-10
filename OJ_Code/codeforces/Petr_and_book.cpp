#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[7];
    for(int i = 0;i < 7;i++) cin >> arr[i];
    int top = 0;
    while(n - arr[top % 7] > 0) {
        n -= arr[(top++) % 7];
    }
    cout << (top % 7) + 1 << endl;
    return 0;
}