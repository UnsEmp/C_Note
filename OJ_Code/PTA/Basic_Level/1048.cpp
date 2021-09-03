#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1,s2;
    vector<char> arr;
    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int len = max(s1.size(),s2.size());
    int temp,temp1,temp2;
    for(int i = 0;i < len;i++){
        temp1 = i < s1.size()?s1[i] - '0':0;
        temp2 = i < s2.size()?s2[i] - '0':0;
        if(i % 2 == 1){
            temp = temp2 - temp1;
            if(temp < 0)
                temp += 10;
            arr.push_back(temp + '0');
        }
        else{
            temp = (temp2 + temp1)  % 13;
            if(temp == 10)
                arr.push_back('J');
            else if(temp == 11)
                arr.push_back('Q');
            else if(temp == 12)
                arr.push_back('K');
            else
                arr.push_back(temp + '0');
        }
    }
    for(int i = arr.size() - 1;i >= 0;i--)
        cout << arr[i];
    return 0;
}