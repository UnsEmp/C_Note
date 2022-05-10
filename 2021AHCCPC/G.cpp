#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> arr(5);
	for(int i = 0;i < 5;++i) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	do {
        bool flag = true;
	    int a = 0, b = 0;
	    for(int i = 0;i < 3;++i) {
	        if(i == 0 && arr[i] == 0) {
                flag = false;
                break;
            }
	        a = a * 10 + arr[i];
	    }
	    for(int i = 3;i < 5;++i) {
	        if(i == 3 && arr[i] == 0) {
                flag = false;
                break;
            }
	        b = b * 10 + arr[i];
	    }
        if(flag) {
            ans = min(ans, a * b);
        }
	}while(next_permutation(arr.begin(), arr.end()));
	cout << ans << "\n";
	return 0;
}