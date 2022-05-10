#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int row = 0,sum = 0;
    char ch;
    cin >> n >> ch;
    for(int i = 1;(2 * sum - 1) <= n;){
        sum += (2 * ++row - 1);
    }
    sum -= (2 * (row--) - 1);
    sum = 2 * sum - 1;
    for(int i = row;abs(i) <= row;i--){
        if(i == 0 || i == -1)
            continue;
        for(int j = abs(i);j < row;j++)
            cout << " ";
        for(int t = 0;t < 2 * abs(i) - 1;t++)
            cout << ch;
        cout << "\n";
    }
    cout << n - sum;
    return 0;
}