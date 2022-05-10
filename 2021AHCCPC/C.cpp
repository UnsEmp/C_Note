#include<bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;

long long quick(long long n, long long m, long long mod) {
    if(m == 0) return 1;
    if(m % 2 == 1) {
        return quick(n, m - 1, mod) * n % mod;
    }
    else {
        long long t = quick(n, m / 2, mod) % mod;
        return t * t % mod;
    }
}

int main(){
	long long sum = 1;
	string s;
	cin >> s;
	for(long long i = 0;i < s.size();++i) {
        // cout << quick(s[i] - '0',i + 1, N) << "\n"; 
	    sum = (sum * quick(s[i] - '0',i + 1, N)) % N;
	}
	cout << sum << "\n";
	return 0;
}