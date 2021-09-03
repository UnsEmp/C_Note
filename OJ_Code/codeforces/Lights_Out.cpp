#include <bits/stdc++.h>
using namespace std;

const int size = 3;

int main()
{
    vector<vector<int>> arr(3, vector<int>(3, 1));
    int ar[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> ans(3, vector<int>(3));
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            int temp;
            cin >> temp;
            ans[i][j] += temp;
            for(int k = 0;k < 4;k++){
                if((i + ar[k][0]) >= 0 && (i + ar[k][0]) < size && (j + ar[k][1]) >= 0 && (j + ar[k][1]) < size){
                    ans[i + ar[k][0]][j + ar[k][1]] += temp;
                }
            }
        }
    }
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(ans[i][j] % 2 == 1){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = 0;
                }
            }
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}