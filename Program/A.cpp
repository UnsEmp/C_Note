#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.size() > s2.size()) {
		cout << -1 << endl;
		return 0;
	}
	else if(s1.size() < s2.size()) {
		sort(s1.begin(), s1.end(), greater<int>());
		cout << s1 << endl;
		return 0;
	}
	sort(s1.begin(), s1.end());
	string s = s1;
//	for(int i = 0;i < s1.size();i++) {
//
//		if(s1[i] > s2[i]) {
//			for(int j = i + 1;j < s1.size();j++) {
//				if(s1[j] <= s2[i]) {
//					swap(s1[j], s1[i]);
//					break;
//				}
//			}
//		}
//		if(s1[i] != s2[i]) break;
//	}
	do {
		if(s < s2) {
			s1 = s;
		}
		else
			break;
	}while(next_permutation(s.begin(), s.end()));
//	int a, b;
//	a = stoi(s1);
//	b = stoi(s2);
	if(s1 < s2 && s1[0] != '0') cout << s1 << endl;
	else cout << -1 << endl; 
	return 0;
}
