#include<bits/stdc++.h>
using namespace std;
int main(){
	
	vector<int> arr(4);
	for(int i = 0;i < 4;++i) cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < 4;++i) cout << arr[i] << " "; 
	return 0;
}