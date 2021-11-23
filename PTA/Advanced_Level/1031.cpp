#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum,left,right,down;
    string s;
    cin >> s;
    left = right = down = (s.size() + 2) / 3;
    if((3 * left - 2) < s.size())
        down += (s.size() + 2) % 3;
    for(int i = 0,j = s.size() - 1;i < left - 1;i++,j--){
        cout << s[i];
        for(int t = 0;t < down - 2;t++)
            cout << " ";
        cout << s[j] << endl;
    }
    for(int i = left - 1;i < s.size() - right + 1;i++)
        cout << s[i];
    return 0;
}