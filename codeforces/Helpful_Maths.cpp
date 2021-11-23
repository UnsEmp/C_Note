#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    unordered_map<int, int> mp;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '+') {
            continue;
        }
        else {
            int temp = s[i] - '0';
            mp[temp]++; 
        }
    }
    vector<int> ans;
    for(int i = 1;i <= 3;i++) {
        for(int j = 0;j < mp[i];j++) {
            ans.emplace_back(i);
        }
    }
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i];
        if(i != ans.size() - 1)
            cout << '+';
    }
    // for(int i = 1;i <= 3;i++) {
    //     if(mp[i - 1]) {
    //         cout << '+';
    //     }
    //     for(int j = 0;j < mp[i];j++) {
    //         cout << i;
    //         if(j != mp[i] - 1)
    //             cout << '+';
    //     }

        
    // }
    return 0;
}