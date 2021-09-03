#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100010];

int BinarySearch(int arr[],int i,int x)
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
    scanf("%d %d",&n,&m);
    int temp,i;
    bool flag = false;
    for(i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr + n);
    for(i = 0;i < n;i++){
        if(m - arr[i] < arr[i]){
            break;
        }
        temp = BinarySearch(arr,i + 1,m - arr[i]);
        if(temp != -1){
            flag = true;
            break;
        }
    }
    if(!flag){
        printf("No Solution");
    }
    else{
        printf("%d %d",arr[i],arr[temp]);
    }
    return 0;
}