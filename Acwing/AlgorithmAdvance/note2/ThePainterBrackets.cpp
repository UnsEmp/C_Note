#include <bits/stdc++.h>
using namespace std;
using LL = long long;
map<char, char> mp;



int main() {
    string s;
    cin >> s;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';
    stack<int> st;
    // vector<pair<int, int>> edges;
    int ans = 0;
    for(int i = 0;i < s.size();++i) {
        if(st.size()) {
            if(mp[s[st.top()]] == s[i]) st.pop();
            else st.push(i);
        }
        else st.push(i);
        if(st.size()) ans = max(ans, i - st.top());
        else ans = max(ans, i + 1);
    }

    cout << ans << "\n";
    return 0;
}