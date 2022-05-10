#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int m,n,t;
    scanf("%d %d",&m,&n);
    string s;
    char a[1001];
    sprintf(a,"%d",n);
    s = a;
    t = s.size();
    for(int i = 0;i < s.size();i++){
        if(s[i] == '1'){
            printf("%c*%d^%d",s[i],m,t-1);
            if(t>1){
                printf("+");
            }
        }
        t--;
    }
    
}