#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> arr(10);
int main()
{
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++)
        arr[s[i] - '0']++;
    for(int i = 0;i < 10;i++){
        if(arr[i] != 0)
            cout << i << ':' << arr[i] << endl;
    }
    return 0;
}