#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int target;
    scanf("%d", &target);
    int arr[n] = {0};
    for(int i = 1;i <= n;i++) {
        scanf("%d", &arr[i]);
    }
    int l = 1, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(arr[mid] >= target) r = mid;
        else l = mid + 1; 
    }
    if(l + 1 < n && arr[l] == target && arr[l + 1] == target) printf("%d", l);
    else if(l < n && arr[l] == target) printf("%d", l);
    else printf("注孤生");
    return 0;
}