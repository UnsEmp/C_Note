#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const char color[14] = {
    "0123456789ABC"
};
void Transform(vector<int> &arr,int n) //对vector进行了引用
{
    int sum = 0;
    do{
        arr.push_back(n % 13);
        n /= 13;
    }while( n );
}
int main()
{
    int n;
    vector<int> arr;
    cout << '#';
    for(int i = 0;i < 3;i++){
        cin >> n;
        Transform(arr,n);
        if(arr.size() == 1)
            cout << '0' << color[arr[0]];
        else
            cout << color[arr[1]] << color[arr[0]];
        arr.clear();
    }
    return 0;
}