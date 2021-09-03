#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr(100010);

int BinarySearch(vector<int> & arr,int i,int x)
{
    int mid,left = i,right = n - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] > x){
            
            right = mid - 1;
        }
        else if(arr[mid] < x){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int temp;
    bool flag = false;
    pair<int,int> ans;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.begin() + n);
    for(int i = 0;i < n;i++){
        if(m - arr[i] < arr[i]){
            break;
        }
        temp = BinarySearch(arr,i + 1,m - arr[i]);
        if(temp != -1){
            ans.first = arr[i];
            ans.second = arr[temp];
            flag = true;
            break;
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