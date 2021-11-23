#include <bits/stdc++.h>
using namespace std;

bool compare(string a,string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    string temp;
    vector<string> s;
    for(int i = 0;i < n;i++){
        cin >> temp;
        s.emplace_back(temp);
    }
    sort(s.begin(),s.end(),compare);
    string ans;
    for(int i = 0;i < n;i++){
        ans += s[i];
    }
    while(ans.size() != 0 && ans[0] == '0'){
        ans.erase(ans.begin());
    }
    if(ans.size() == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0;i < ans.size();i++){
        cout << ans[i];
    }
    return 0;
}