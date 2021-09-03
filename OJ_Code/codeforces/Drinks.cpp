#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double temp, sum = 0.0;
    for(int i = 0;i < n;i++) {
        cin >> temp;
        sum += temp;
    }
    cout << sum / n << endl;
    return 0;
}