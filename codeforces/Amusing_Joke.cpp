#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s;
    bool flag = true;
    unordered_map<int, int> mp;
    cin >> s1 >> s2 >> s;
    if((s1.size() + s2.size()) != s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0;i < s.size();i++) {
        mp[s[i]]++;
    }
    for(int i = 0;i < s1.size();i++) {
        mp[s1[i]]--;
        if(mp[s1[i]] < 0)
            flag = false;
    }
    for(int i = 0;i < s2.size();i++) {
        mp[s2[i]]--;
        if(mp[s2[i]] < 0)
            flag = false;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}