#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
    cin >> n;
    vector<long long> arr(n);
    for(long long i = 0;i < n;++i) cin >> arr[i];
    long long ans = 0;
    long long xo = 0, sum = 0;
    for(long long i = 0, j = 0;i < n;++i) {
        while(j < n && (xo ^ arr[j]) == (sum + arr[j])) {
            xo = xo ^ arr[j];
            sum = sum + arr[j];
            j++;
        }
        ans += (j - i);
        sum -= arr[i];
        xo ^= arr[i];
        
    }
    cout << ans << "\n";
	return 0;
}