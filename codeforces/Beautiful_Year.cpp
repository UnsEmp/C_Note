#include <bits/stdc++.h>
using namespace std;

bool judge(int n)
{
    map<int, int> mp;
    while(n){
        if(mp[n % 10])
            return false;
        mp[n % 10]++;
        n /= 10;
    }
    return true;
}

int main()
{
    int n, i; 
    cin >> n;
    for(i = n + 1;;i++){
        if(judge(i))
            break;
    }
    cout << i << endl;
    return 0;
}