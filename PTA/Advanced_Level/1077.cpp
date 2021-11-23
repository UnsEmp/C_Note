#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    int minlen = 256;
    bool flag = true;
    vector<char> arr;
    cin >> n;
    getchar();
    string s[n];
    for(int i = 0;i < n;i++){
        getline(cin,s[i]);
        reverse(s[i].begin(),s[i].end());
        if(s[i].size() < minlen)
            minlen = s[i].size();
    }
    int i,j;
    for(i = 0;i < minlen;i++){
        for(j = 1;j < n;j++){
            if(s[j-1][i] != s[j][i]){
                flag = false;
                break;
            }
        }
        if(!flag)
            break;
        else
            arr.push_back(s[j-1][i]);
    }
    if(arr.size() != 0){
        for(int i = arr.size() - 1;i >= 0;i--){
            cout << arr[i];
        }
    }
    else
        cout << "nai" << endl;
    return 0;
}