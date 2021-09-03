#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr,int i,int x)
{
    int mid,left = i,right = arr.size();
    while(left < right){
        mid = (left + right) / 2;
        if(arr[mid] > x){
            left = mid + 1;
        }
        else if(arr[mid] < x){
            right = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int temp;
    bool flag = false;
    pair<int,int> ans;
    vector<int> arr;
    for(int i = 0;i < n;i++){
        cin >> temp;
        arr.emplace_back(temp);
    }
    for(int i = 0;i < n;i++){
        temp = BinarySearch(arr,i + 1,m - arr[i]);
        if(temp != -1){
            ans.first = arr[i];
            ans.second = arr[temp];
            flag = true;
        }
    }
    if(!flag){
        cout << "No Solution";
    }
    else{
        cout << ans.first << " " << ans.second;
    }
    return 0;
}