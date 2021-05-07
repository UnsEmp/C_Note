#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char arr[n+2];
    for(int i = 1;i <= n+1;i++){
        arr[i] = 'A' + i - 1;
    }
    for(int i = n;i > 0;i--){
        for(int j = 0;j < (2*i - 1)/2;j++){
            cout << " ";
        }
        int t;
        for(t = 1;t < n - i + 1;t++){
            cout << arr[t];
        }
        for(;t > 0;t--){
            cout << arr[t];
        }
        cout << "\n";
    }
    return  0;
}