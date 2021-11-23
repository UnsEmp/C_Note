#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n, left = 0;
    string s;
    cin >> n >> s;
    int count = 0;
    for(int i = 1;i < n;i++){
        if(s[i] != s[left]){
            left = i;
            continue;
        }
        else{
            count++;
        }
    }
    cout << count << endl;
    return 0;
}