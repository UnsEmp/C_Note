#include <bits/stdc++.h>
using namespace std;

#define MAX 600

class Solution {

public:
    bool KMP(string &p, string &s, int m) {
        int n = p.size();
        int ne[n + 1];
        ne[1] = 0;
        for(int i = 2, j = 0;i <= n;i++) {
            while(j && p[i] != p[j + 1]) j = ne[j];
            if(p[i] == p[j + 1]) j++;
            ne[i] = j;
        }
        for(int i = 1, j = 0;i <= m;i++) {
            while(j && p[j + 1] != s[i]) j = ne[j];
            if(p[j + 1] == s[i]) j++;
            if(j == n - 1) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(b == "") return 0;
        b.insert(b.begin(), ' ');
        string s = " ";
        int n = a.size(), m = b.size(), count = 0;
        int l = 0, r = 1e4 + 1, mid;
        for(int i = 0;i <= r;i++) {
            s += a;
        }
        while(l < r) {
            cout << l << " " << r << endl;
            mid = (l + r) >> 1;

            if(KMP(b, s, mid * n + 1)) r = mid;
            else l = mid + 1;
        }
        return l >= 1e4 + 1?-1:l;
    }
};

int main()
{
	// Solution so;
	// so.repeatedStringMatch("a", "aa");
    cout << "a";
    cout << char('0') << endl;
	return 0;
}
