#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, c;
    cin >> n >> c;
    long long arr[n + 1];
    long long count = 0;
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r1 = 0, r2 = 0;
    for(int l = 0;l < n;l++) {
        while(r1 < n && arr[r1] - arr[l] <= c) r1++;
        while(r2 < n && arr[r2] - arr[l] < c) r2++;
        if(r1 - 1 >= 0 && arr[r2] - arr[l] == c && arr[r1 - 1] - arr[l] == c) count += r1 - r2;
    }
    cout << count << endl;
    return 0;
}