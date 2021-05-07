#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    int temp;
    for(int i = 0;i < m;i++){
        temp = arr[n-1];
        for(int j = n - 1;j > 0;j--)
            arr[j] = arr[j-1];
        arr[0] = temp;
    }
    for(int i = 0;i < n;i++){
        cout << arr[i];
        if(i != (n - 1))
            cout << " ";
    }
    return 0;
}