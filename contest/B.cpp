#include <bits/stdc++.h>
using namespace std;

int fun(string s, int k) {
        int MaxSlen = 0, MaxQlen = 0;
        int n = s.size();
        int i = 0, j = 0, countS = 0, countQ = 0;
        while(j < n) {
            if(s[j] == 'Q') {
                countQ ++;
                while(countQ > k) {
                    if(s[i] == 'Q') countQ --;
                    i++;
                }
            }
            MaxSlen = max(MaxSlen, j - i + 1);
            j++;
        }
        i = j = 0;
        while(j < n) {
            if(s[j] == 'S') {
                countS ++;
                while(countS > k) {
                    if(s[i] == 'S') countS --;
                    i++;
                }
            }
            MaxQlen = max(MaxQlen, j - i + 1);
            j++;
        }
        return max(MaxQlen, MaxSlen);
    }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    cout << fun(s, k) << "\n";
    return 0;
}