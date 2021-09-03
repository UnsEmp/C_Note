#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;

int main()
{
    int arr[MAX][MAX];
    int i, j;
    bool flag = false;
    for(i = 0;i < MAX;i++){
        for(j = 0;j < MAX;j++){
            cin >> arr[i][j];
        }
    }
    for(i = 0;i < MAX;i++){
        for(j = 0;j < MAX;j++){
            if(arr[i][j] == 1){
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    cout << abs(i - 2) + abs(j - 2);
    return 0;
}