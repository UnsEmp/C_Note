#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> ne(N);

int main() {
    int n, m;
    string p, s;
    cin >> n >> s >> m >> p;
    ne[0] = -1;
    for(int i = 1, j = -1;i < n;++i) {
        while(j >= 0 && s[i] != s[j + 1]) j = ne[j];
        if(s[j + 1] == s[i]) j ++;
        ne[i] = j;
    }
    for(int i = 0, j = -1;i < m;++i) {
        while(j >= 0 && p[i] != s[j + 1]) j = ne[j];
        if(s[j + 1] == p[i]) j ++;
        if(j == n - 1) {
            cout << i - n + 1 << " ";
            j = ne[j];
        }
    }
    return 0;
}