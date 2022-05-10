#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 2, 4, 6, 7, 9, 11, 11, 12};
    int l = 0, r = 9, target = 2;
    while(l < r) {
        int mid = (l + r) / 2;
        if(arr[mid] >= target) r = mid;
        else l = mid + 1;
    }X
    printf("%d", arr[l]);
    return 0;
}