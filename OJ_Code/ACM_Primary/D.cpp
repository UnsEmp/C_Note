#include <bits/stdc++.h>
using namespace std;
const int mul = 1000000007;
long long g(long long x,long long n)
{
    long long LL;
    if(n == 0)
        return 1;
    if(n % 2 == 1){
        return x * g(x,n-1) % mul;
    }
    else{
        LL =  g(x,n/2);
        return LL * LL % mul;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long sum = 1;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        sum *= g((s[i] - '0'),i + 1);
        sum %= mul;
    }
    cout << sum;
    return 0;
}