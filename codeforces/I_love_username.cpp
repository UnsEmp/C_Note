#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    cin >> n >> temp;
    n--;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int Max = temp, Min = temp, count = 0;
    while(n--) {
        cin >> temp;
        if(temp > Max) {
            Max = temp;
            count++;
        }
        if(temp < Min) {
            Min = temp;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}