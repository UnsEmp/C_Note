#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int compare(int a,int b)
{
    return a > b;
}
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
    int temp = 0,max = 0;
    string arr,brr;
    int b;
    cin >> arr;
    cin >> brr;
    int len1 = arr.size();
    int len2 = brr.size();
    b = Transform(brr);
    sort(arr.begin(),arr.end());
    if(len1 > len2){
        cout << "-1";
    }
    else if(len1 < len2)
    {
        sort(arr.begin(),arr.end(),compare);
        cout << arr;
    }
    else{
        do{
            if(arr[0] == '0')
            continue;
            temp = Transform(arr);
            if(temp > max && temp <= b)
            max = temp;
        }while(next_permutation(arr.begin(),arr.end()));
        if(max)
        cout << max;
        else
        cout << "-1";
    }
    return 0;
}