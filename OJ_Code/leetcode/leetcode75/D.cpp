#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string s = "azbazbzaz";
    int n = s.size();
    int l = 0, r = 0;
    int res[101000];
    for (int i = 1; i < n; i++) 
    {
        if (i > r) 
        {
            l = r = i;
            while (r < n && s[r-l] == s[r]) 
            {
                r++;
            }
            res[i] = r-l; 
            r--;
        } 
        else 
        {
            int k = i-l;
            if (res[k] < r-i+1) 
            {
                res[i] = res[k];
            } 
            else 
            {
                l = i;
                while (r < n && s[r-l] == s[r]) 
                {
                    r++;
                }
                res[i] = r-l; 
                r--;
            }
        }
        // cout << l << " " << r << "\n";
    }
    for(int i = 0;i < n;++i) {
        cout << res[i] << " ";
        ans += res[i];
    }
    cout << "\n";
    cout << ans + n << "\n";
    return 0;
}