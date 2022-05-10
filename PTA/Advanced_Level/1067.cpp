#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,temp,count = 0;
    cin >> n;
    vector<int> arr(n);
    int left = n - 1;
    for(int i = 0;i < n;i++){
        cin >> temp;
        arr[temp] = i;
        if(arr[temp] == temp && temp != 0){
            left--;
        }
    }
    int i = 1;
    while(left > 0){
        if(arr[0] == 0){
            for(;i < n;i++){
                if(arr[i] != i){
                    swap(arr[i],arr[0]);
                    count++;
                    break;
                }
            }
        }
        while(arr[0] != 0){ //只要arr[0] ！= 0的话就可以一直进行交换
            temp = arr[0];
            swap(arr[0],arr[temp]);
            left--;
            count++;
        }

    }
    cout << count << endl;
    return 0;
}