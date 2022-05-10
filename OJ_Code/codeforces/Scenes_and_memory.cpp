#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

bool isprime(int n) {
    if(n == 1) return false;
    for(int i = 2;i <= n / i;++i)
        if(n % i == 0) return false; 
    return true;
} 

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int num = 0, cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0;i < s.size();++i) {
            if(!isprime(s[i] - '0')) {
                cout << "1" << "\n" << s[i] << "\n";
                return ;
            }
        }
        for(int i = 0;i < s.size();++i) {
            if(!isprime(s[i] - '0')) {
                cout << "1" << "\n" << s[i] << "\n";
                return ;
            }
            for(int j = i + 1;j < s.size();++j) {
                if(!isprime((s[i] - '0') * 10 + (s[j] - '0'))) {
                    cout << "2" << "\n" << (s[i] - '0') * 10 + (s[j] - '0') << "\n";
                    return ;
                }
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}
