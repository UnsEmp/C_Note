#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(2));
	for(int i = 0;i < n;i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int count = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
          if(j == i) continue;
			if(arr[j][0] < arr[i][0] && arr[i][1] < arr[j][1]) {
				count++;
				break;
			}
		}
	}
	cout << count << endl;
	return 0;
}
