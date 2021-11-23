#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IfPalindromic(vector<int>& arr);

int main()
{
    int n,k;
    vector<int> num;
    cin >> n >> k;
    do{
        num.push_back(n%k);
        n /= k;
    }while( n );
    if( IfPalindromic(num) ) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = num.size() - 1;i >= 0;i--){
        cout << num[i];
        if(i != 0)
            cout << " ";
    }
    return 0;
}

bool IfPalindromic(vector<int>& arr)
{
    bool flag = true;
    for(int i = 0,j = arr.size() - 1;i < j;i++,j--){
        if(arr[i] != arr[j]){
            flag = false;
            break;
        }
    }
    return flag;

}