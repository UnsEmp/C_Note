#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;


template <typename T, typename W>
vector<int> KMP(T &p, T &s, W m, W n) {
    unordered_map<W, W> ne;
    vector<W> ans;
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            // cout << i - j << ' ';
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    return ans;
}

class Solution {
public:
    int countCollisions(string d) {
        int ans = 0;
        int n = d.size();
        stack<char> st;
        for(int i = 0;i < n;++i) {
            if(!st.empty()) {
                if(st.top() == 'R')  {
                    if(d[i] == 'L') {
                        ans += 2;
                        st.pop();
                        while(!st.empty() && st.top() == 'R') {
                            ans ++;
                            st.pop();
                        } 
                        st.push('R');
                    }
                    else if(d[i] == 'S') {
                        ans += 1;
                        st.pop();
                        while(!st.empty() && st.top() == 'R') {
                            ans ++;
                            st.pop();
                        }
                        st.push('R');
                    }
                }
                else if(st.top() == 'S') {
                    if(d[i] == 'L') ans += 1;
                }
                else {
                    if(d[i] == 'L') ans += 1;
                }
                // cout << ans << "\n";
            }
            if(!st.empty()) st.push(d[i]);
            else {
                if(d[i] == 'R' || d[i] == 'S') st.push(d[i]);
            }
        }
        return ans;
    }
};