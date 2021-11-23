#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int temp;
    string s;
    cin >> s;
    if(s.size() == 3){
        temp = s[0] - '0';
        for(int i = 0;i < temp;i++)
            cout << 'B';
        temp = s[1] - '0';
        for(int i = 0;i < temp;i++)
            cout << 'S';
        temp = s[2] - '0';
        for(int i = 1;i <= temp;i++)
            cout << i;
    }
    else if(s.size() == 2){
        temp = s[0] - '0';
        for(int i = 0;i < temp;i++)
            cout << 'S';
        temp = s[1] - '0';
        for(int i = 1;i <= temp;i++)
            cout << i;
    }
    else{
        temp = s[0] - '0';
        for(int i = 1;i <= temp;i++)
            cout << i;
    }
    return 0;
}