#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a,n;
    cin >> a >> n;
    string s;
    int temp=0,t;
    for(int i = n;i > 0;i--){
        temp += i*a;
        s.push_back(temp%10);
        temp/=10;
    }
    if(temp){
        s.push_back(temp%10);
        temp/=10;
    }
    if(n != 0){
        for(int i = s.size() - 1;i >= 0;i--){
            printf("%d",s[i]);
        }
    }
    else{
        cout << 0;
    }
    return 0;
}