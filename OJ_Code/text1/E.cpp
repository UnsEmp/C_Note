#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int count = 0, row = 0, col = 0;
	for(int i = 0;i < s.size();i++) {
		// if(i % 20 == 0) cout << endl;
		if(s[i] == '1' || s[i] == '0') {
			cout << s[i] << " ";
			count++;
			if(count % 3 == 0) {
				row++;
				cout << endl;
			}
		}
	}
	cout << row << " " << count / row << endl;
	return 0;
}