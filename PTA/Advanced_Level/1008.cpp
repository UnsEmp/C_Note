#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int temp,top = 0,sum = 0;
    for(int i = 0;i < n;i++){
        cin >> temp;
        if(temp > top){
            sum += (temp - top) * 6 + 5;
            top = temp;
        }
        else{
            sum += (top - temp) * 4 + 5;
            top = temp;
        }
    }
    cout << sum;
    return 0;
}