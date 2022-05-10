#include <bits/stdc++.h>
using namespace std;

bool IfNum(int n)
{
    bool flag = true;
    for(int i = 2;i <= (int)sqrt(1.0 * n);i++){
        if(n % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}


int main()
{
    int m,n;
    int count = 0,temp = 0;
    cin >> m >> n;
    for(int i = 2;count < n;i++){
        if( IfNum(i) ){
            count++;
            if(count >= m){
                temp++;
                cout << i;
                if((temp) % 10 == 0 && count != n)
                    cout << "\n";
                else if((temp) % 10 != 0 && count != n)
                    cout << " ";
            }
        }
    }
    return 0;
}