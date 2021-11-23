#include <iostream>
#include <cstdbool>
#include <algorithm>
using namespace std;

bool compare(int a,int b)
{
    return a < b;
}

int BinarySearch(int arr[],long long X,int left,int right)
{
    int might;
    if(arr[right] <= X)
    return right + 1; // 如果最右边最大的数都小于 X ，则其他的数都小于 X；
    while(right > left){
        might = (right + left)/2;
        if(arr[might] > X){ // arr[might] > X 说明第一个大于X的数一定在might的左边或者就是might
            right = might;
        }
        else{
            left = might + 1; //说明第一个大于X的数的位置在右边
        }
    }
    return left;
}

int main()
{
    long long N,p;
    int sum = 0;
    cin >> N;
    cin >> p;
    int arr[N];
    for(int i = 0;i < N;i++){
        cin >> arr[i];
    }
    sort(arr,arr + N,compare);
    int left = 0,right = N - 1;
    for(int i = 0;i < N;i++){  //总共进行 n 次循环，在[i + 1 ， n - 1]的范围内寻找第一个大于 arr[i] * p 的位置；
        int j = BinarySearch(arr,(long long)(arr[i] * p),left,right);
        sum = max(sum,j - i); // 不断更新最大值
    }
    printf("%d",sum);
    return 0;
}