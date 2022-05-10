#include <stdio.h>
#include <stdbool.h>

int BinarySearch(int arr[], int left, int right, int target) //找到返回对应元素的下标，否则返回-1
{
    while(left <= right) {
        int mid = left - (left - right) / 2; //(l + r) / 2;
        if(target > arr[mid]) left = mid + 1;
        else if(target < arr[mid]) right = mid - 1;
        else return mid;
    }
    return -1;
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    int arr[n];
    for(int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
    }
    bool flag = false;
    for(int i = 0;i < n;i++) {
        int tmp = l - arr[i];
        if(BinarySearch(arr, i + 1, n - 1, tmp) != -1) {
            flag = true;
            printf("YES");
            break;
        }
    }
    if(flag == false) printf("NO");
    return 0;
}