#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g(int n)
{
    int sum = 1;
    for(int i = 0;i < n;i++){
        sum *= 10;
    }
    return sum;
}

int Transform(string arr)
{
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += (int)(arr[i] - '0') * g(n-i-1);
    }
    return sum;
}

int main()
{
    // string arr;
    // int brr,max = 0,temp = 0;
    // cin >> arr;
    // cin >> brr;
    // while(next_permutation(arr.begin(), arr.end())) {
    //     int i = 0;
    //     if(arr[i] == '0')
    //     continue;
    //     temp = Transform(arr);
    //     if(temp > max && temp <= brr)
    //     max = temp;        
    // }
    // if(arr[0] == '0')
    // cout << -1;
    // else
    // cout << max;
    printf("%c", '9' + 1);
    return 0;
}