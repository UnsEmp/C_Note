#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int count = 0;
    bool flag = true;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '4' || s[i] == '7')
            count++;
    }
    // if(count == 0){
    //     cout << "NO" << endl;
    //     return 0;
    // }
    // cout << count << endl;
    if(count == 4 || count == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}