#include <bits/stdc++.h>
using namespace std;

int n,m;
int brr[100010] = {0}; 
int Max = 100000010;
int BinarySearch(int brr[],int x,int i)
{
    int left = i,right = n + 1,mid;
    while(left < right){
        mid = (left + right) / 2;
        if(brr[mid] > x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main()
{

    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&brr[i]);
        brr[i] += brr[i-1];
    }
    for(int i = 1;i <= n;i++){
        int temp = BinarySearch(brr,brr[i-1] + m,i);
        if(brr[temp-1] - brr[i-1] == m){
            Max = m;
            break;
        }
        else if(brr[temp] - brr[i-1] < Max && temp <= n){
            Max = brr[temp] - brr[i-1];
        }
    }
    for(int i = 1;i <= n;i++){
        int temp = BinarySearch(brr,brr[i-1] + Max,i);
        if(brr[temp-1] - brr[i-1] == Max){
            printf("%d-%d\n",i,temp-1);
        }
    }
    return 0;
}