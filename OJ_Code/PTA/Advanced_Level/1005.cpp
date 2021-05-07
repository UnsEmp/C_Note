#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fun(int n)
{
    switch(n)
    {
        case 0: cout << "zero";break;
        case 1: cout << "one";break;
        case 2: cout << "two";break;
        case 3: cout << "three";break;
        case 4: cout << "four";break;
        case 5: cout << "five";break;
        case 6: cout << "six";break;
        case 7: cout << "seven";break;
        case 8: cout << "eight";break;
        case 9: cout << "nine";break;
    }
}
long long g(int n)
{
    long long sum = 1;
    for(int i = 0;i < n;i++){
        sum *= 10;
    }
    return sum;
}
int main()
{
    int sum = 0;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        sum += (s[i] - '0');
    }
    vector<int> arr;
    do{
        arr.push_back(sum%10);
        sum /= 10;
    }while(sum);
    for(int i = arr.size() - 1;i >= 0;i--){
        fun(arr[i]);
        if(i != 0)
        cout << " ";
    }
    return 0;
}