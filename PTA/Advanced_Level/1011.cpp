#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    vector<char> ar(3);
    double a,Max,sum = 1;
    for(int i = 0;i < 3;i++){
        cin >> a;
        Max = a;
        ar[i] = 'W';
        cin >> a;
        if(a > Max){
            ar[i] = 'T';
            Max = a;
        }
        cin >> a;
        if(a > Max){
            ar[i] = 'L';
            Max = a;
        }
        sum *= Max;
        cout << ar[i] << " ";
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << (sum * 0.65 - 1) * 2;
    return 0;
}