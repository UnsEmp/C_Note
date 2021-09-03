#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    long long n;
    cin >> n;
    int i,c,c1,c2;
    long long sum = 0;
    for(i = 1;i <= 2 * n + 1;i++){
        if(i <= n + 1){
            sum += i * i;
        }
        else{
            sum -= i * i;
        }
    }
    long long left = (long long)(sqrt((double)((long long)(n * n * n * n) - sum))) + n * n;
    for(int i = left;i <= left + 2 * n;i++){
        cout << i << "^2";
        if(i == left + 2 * n)
            break;
        if((i < (left + 2 * n)) && i!= left + n){
            cout << " + ";
        }
        else{
            cout << " = ";
        }
    }
    return 0;
}