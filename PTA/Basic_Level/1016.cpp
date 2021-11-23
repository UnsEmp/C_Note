#include <iostream>
#include <string>
using namespace std;
int g(int n)
{
    int sum = 1;
    for(int i = 0;i < n;i++){
        sum *= 10;
    }
    return sum;
}
int main()
{
    string s1,s2;
    int num1,num2;
    int count1 = 0,count2 = 0,sum1 = 0,sum2 = 0;
    cin >> s1 >> num1 >> s2 >> num2;
    for(int i = 0;i < s1.size();i++){
        if((s1[i] - '0') == num1)
        count1++;        
    }
    for(int i = 0;i < s2.size();i++){
        if((s2[i] - '0') == num2)
        count2++;
    }
    for(int i = count1 - 1;i >= 0;i--){
        sum1 += num1 * g(i);        
    }
    for(int i = count2 - 1;i >= 0;i--){
        sum2 += num2 * g(i);
    }
    cout << sum1 + sum2;
    return 0;
}