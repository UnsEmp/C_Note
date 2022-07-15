#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int cnt = 0;

void insert(int x) {
	a[cnt++] = x;
}

void up(int p) {
	while(p / 2 && a[p / 2] > a[p]) {
		swap(a[p / 2], a[p]);
		up(p / 2);
	}
}

void down(int p) {
	while(p * 2)
}

int pop() {

}

int main() {
	int n;
	cin >> n;
	// vector<int> a(n + 1);
	for(int i = 1;i <= n;++i) {
		int t;
		cin >> t;
		insert(x);
		up(i);
	}	
}