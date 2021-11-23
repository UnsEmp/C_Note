#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    while(n++){
        bool flag = true;
        for(int i = 2;i < n;i++){
            if(n % i == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    printf("%s",(n == m)?"YES":"NO");
    return 0;
}