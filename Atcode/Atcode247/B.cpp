#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_map<string, int> mp;
    int n;
    cin >> n;
    vector<vector<string>> arr(n);
    for(int i = 0;i < n;++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.size() == s2.size() && s1 == s2) {
            mp[s1] ++;
            
        }
        else {
            mp[s1] ++;
            mp[s2] ++;
        }
        arr[i].push_back(s1);
        arr[i].push_back(s2);
    }
    for(int i = 0;i < n;++i) {
        if(mp[arr[i][0]] == 1 || mp[arr[i][1]] == 1) continue;
        else {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}























