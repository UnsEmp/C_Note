#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char, int> mp;
    string s;
    int count = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(!mp[s[i]]) {
            count++;
            mp[s[i]]++;
        }
    }
    if(count % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
}