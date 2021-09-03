#include <bits/stdc++.h>
using namespace std;

int leftarr[100010] = {0};


int main()
{
    int Max = 0,right = 0;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(i > 0){
            leftarr[i] = leftarr[i - 1];
        }
        if(s[i] == 'P'){
            leftarr[i]++;
        }
    }
    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == 'T'){
            right++;
        }
        else if(s[i] == 'A'){
            Max += (leftarr[i] * right);
            Max %= 1000000007;
        }
    }
    cout << Max;
    return 0;
}