#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    string s1,s2;
    string::iterator it = s1.begin();
    int num1,num2;
    cin >> s1 >> num1 >> s2 >> num2;
    int i = 0,j = 0;
    while(i < s1.size()){
        if(s1[i] != (num1 + '0'))
            s1.erase(s1.begin() + i);
        else
            i++;
    }
    while(j < s2.size()){
        if(s2[j] != (num2 + '0'))
            s2.erase(s2.begin() + j);
        else
            j++;
    }
    cout << atoi(s1.c_str()) + atoi(s2.c_str());
    return 0;
}